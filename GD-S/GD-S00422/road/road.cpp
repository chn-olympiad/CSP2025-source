#include <iostream>
#include <fstream>
using namespace std;


int grp[10010][10010];
int n,m,k;
int mincs = 1000000;
void D(int ct,int cs,int loli)
{
	if(ct >= n)
	return;
	if(loli == n-1)
	{
		if(cs < mincs)
			
			{
				mincs = cs;
				
			}
			return;
	}
	if(grp[ct][ct] != 0)
	return;
	grp[ct][ct] = 1;
	//cout << "PP1";
	for(int i = 0; i < n;i++)
	{
		if(i != ct && (grp[ct][i] > 0 || grp[i][ct] > 0))
		{
			//cout << "R1";
			cs += grp[ct][i];
			loli += 1;
			D(i,cs,loli);
			loli -=1;
			cs -= grp[ct][i];
		}
	}
	for(int i = 0; i < k;i++)
	{
		if(grp[10000+i][10000+i] != 0)
		{
			int v = grp[10000+i][10000+i];
			grp[10000+i][10000+i] = 0;
			D(i,cs,loli);
			
			grp[10000+i][10000+i] = v;
		}
	}
	grp[ct][ct] = 0;
}

int main()
{
	ifstream fi("road.in");
	ofstream fo("road.out");
	
	fi >> n >> m >> k;
	
	int u,v,w;
	
	for(int i = 0 ; i < m; i ++)
	{
		fi >> u >> v >> w;
		u--;
		v--;
		grp[u][v] = w;//fix cost
		grp[v][u] = w;
	}
	for(int i= 0 ; i<k;i++)
	{
		fi >> u;
		grp[10000+i][10000 +i] = u;//mord cost
		for(int q = 0;q < n;q++)
		{
			fi >> v;
			grp[10000+i][q] = v;//build cost
			grp[q][10000+i] = v;//build cost
		}
	}
	D(0,0,0);
	fo << mincs;
	
}
