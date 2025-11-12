#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],AK,x=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
		s[i]=-1*s[i];
	}
	AK=s[1];
	sort(s+1,s+n*m+1);
	for(int j=1;j<=m;j++)
	{
		if(j&1)
		{
			for(int i=1;i<=n;i++,x++)
			{
				if(s[x]==AK)
				{
					cout<<j<<" "<<i;
					exit(0);
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--,x++)
			{
				if(s[x]==AK)
				{
					cout<<j<<" "<<i;
					exit(0);
				}
			}
		}
	}
	return 0;
}
//AC!!!!
