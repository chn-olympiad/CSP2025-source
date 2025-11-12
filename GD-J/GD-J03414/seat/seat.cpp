#include<bits/stdc++.h>
using namespace std;

int n,m,a1;
vector<int> a;

bool cmp(int a,int b)
{
	return a>b;
}

void bfs(int x,int y,int z,int fl)
{
	if(a[z]==a1)
	{
		cout<<x<<" "<<y;
		return ;
	}
	else{
		if(fl==1)
		{
			if(y+1>n)
			{
				bfs(x+1,y,z+1,2);
			}
			else 
			{
				bfs(x,y+1,z+1,1);
			}
		}
		else
		{
			if(y-1<=0)
			{
				bfs(x+1,y,z+1,1);
			}
			else 
			{
				bfs(x,y-1,z+1,2);
			}
		}
	}
}


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	a.push_back(a1);
	for(int i=1;i<n*m;i++)
	{
		int q;
		cin>>q;
		a.push_back(q);
	}
	sort(a.begin(),a.end(),cmp);
	bfs(1,1,0,1);
	return 0;
 } 
