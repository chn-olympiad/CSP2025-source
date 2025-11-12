#include<bits/stdc++.h>
using namespace std;
int x[10000],s[1000][1000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,m,t,f=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x[i];
	}
	t=x[1];
	sort(x+1,x+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int l=1;l<=n;l++)
			{
				f++;
				if(x[f]==t)
				{
					cout<<i<<" "<<l;
				}
			}
		}
		if(i%2==0)
		{
			for(int l=n;l>=1;l--)
			{
				f++;
				if(x[f]==t)
				{
					cout<<i<<" "<<l;
				}
			}
		}
	}
    return 0;
}
