#include <bits/stdc++.h>
using namespace std;
int a[110],s[20][20];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++) cin>>a[i];
	R = a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt = 0;
	for(int i = 1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j = 1;j<=n;j++)
			{
				cnt++;
				s[j][i] = a[cnt];
			}
		}
		else
		{
			for(int j = n;j>=1;j--)
			{
				cnt++;
				s[j][i] = a[cnt];
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(s[j][i]==R) cout<<i<<" "<<j;
		}
	}
	return 0;
}