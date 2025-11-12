#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int i,j,n,m,score,cnt=0,lie,hang;
	cin>>n>>m;
	int a[n+1][m+1],pts[n*m+1],tot=n*m;
	bool flag=false;
	for(i=1;i<=tot;i++) cin>>pts[i];
	if(n==1&&m==1)
	{
		cout<<"1 1";
		return 0;
	}
	score=pts[1];
	sort(pts+1,pts+tot+1,cmp);
	
	if(m%2)
	{
		for(i=1;i<=m-1;i+=2)
		{
			for(j=1;j<=n;j++)
			{
				cnt++;
				if(pts[cnt]==score)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			for(j=n;j>=1;j--)
			{
				cnt++;
				if(pts[cnt]==score)
				{
					cout<<i+1<<" "<<j;
					return 0;
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			cnt++;
			if(pts[cnt]==score)
			{
				cout<<m<<" "<<j;
				return 0;
			}
		}
	}
	else
	{
		for(i=1;i<=m;i+=2)
		{
			for(j=1;j<=n;j++)
			{
				cnt++;
				if(pts[cnt]==score)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			for(j=n;j>=1;j--)
			{
				cnt++;
				if(pts[cnt]==score)
				{
					cout<<i+1<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
