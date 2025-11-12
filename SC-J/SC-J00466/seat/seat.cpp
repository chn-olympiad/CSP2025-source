#include <bits/stdc++.h>
using namespace std;
int n,m,l,pzx;
int grade[105];
int mp[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>grade[i];
	l=grade[1];
	sort(grade+1,grade+1+n*m,cmp);
	for (int i=1;i<=m;i++)
	{
		if (i%2)
		{
			for (int j=1;j<=n;j++)
			{
				pzx++;
				mp[j][i]=grade[pzx];
			}
		}
		else
		{
			for (int j=n;j>0;j--)
			{
				pzx++;
				mp[j][i]=grade[pzx];
			}
		}
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (mp[j][i]==l)
				cout<<i<<" "<<j; 
	return 0;
}