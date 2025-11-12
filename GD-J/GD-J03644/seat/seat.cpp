#include<bits/stdc++.h>
using namespace std;
int n,m,x,b[110],t,w=0,e=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>x;
	b[1]=x;
	for(int i=2;i<=n*m;i++) cin>>b[i];
	sort(b+1,b+n*m+1);
	t=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[t]==x)
				{
					w=i;
					e=j;
					break;
				}
				t--;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(b[t]==x)
				{
					w=n;
					e=m;
					break;
				}
				t--;
			}
		}
		if(w!=0&&e!=0) break;
	} 
	cout<<w<<" "<<e;
	return 0;
} 
