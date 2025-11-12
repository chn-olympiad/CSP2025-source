#include<bits/stdc++.h>
using namespace std;
int qp[20][20];
int n,m;
int cj[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>cj[i];
	}
	int t=cj[1];
	sort(cj+1,cj+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(cj[i]==t)
		{
			t=i;
			break;
		}
	}
	int cnt=0;
	int ud=0;//1ио0об 2ср 
	int x=1,y=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cnt++;
			//cout<<x<<" "<<y<<"->";
			//cout<<ud<<" ";
			if(ud==0) x++;
			if(ud==1) x--;
			if(ud==2)
			{
				y++;
				if(y%2==0)
				{
					ud=1;
				}
				else
				{
					ud=0;
				}
			}
			//cout<<x<<" "<<y<<endl;
			if(ud==0&&x==n || ud==1&&x==1)
			{
				ud=2;
			}
			
			if(cnt==t-1)
			{
				cout<<y<<" "<<x<<endl;
				return 0;
			}
		}
	}
	
	
	
}
