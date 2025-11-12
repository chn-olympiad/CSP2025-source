#include<bits/stdc++.h>
using namespace std;
int n,m;
struct st{
	int x;
	int xh;
}s[103];
bool cmp(st a,st b)
{
	return a.x>b.x;
}
int w[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >>n >>m;
	for(int i=1;i<=n*m;i++)
	{
		cin >>s[i].x;
		s[i].xh=i;
	}
	sort(s+1,s+1+n*m,cmp);
	int pos=1,ans=1,z=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[z].xh==1)
			{
				cout <<ans <<" " <<pos;				
				return 0;
			}
			if(ans%2==1)
			{
				if(pos<m)
				{
					w[pos][ans]=s[z].xh;
					z++;
					pos++;	
//					cout <<ans <<" " <<pos <<endl;	
				}
				else
				{
					ans++;
					w[pos][ans]=s[z].xh;
					z++;
//					cout <<ans <<" " <<pos <<endl;	
				}
			}
			else
			{
				if(pos>1)
				{
					w[pos][ans]=s[z].xh;
					z++;
					pos--;	
//					cout <<ans <<" " <<pos <<endl;	
				}
				else
				{
					ans++;
					w[pos][ans]=s[z].xh;
					z++;
//					cout <<ans <<" " <<pos <<endl;	
				}				
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
