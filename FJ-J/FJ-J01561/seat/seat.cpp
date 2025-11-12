#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
ll n,m,i,j,a[N],b[N][N],num,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(i=1;i<=m;i++)
	  if(i%2) for(j=1;j<=n;j++) b[j][i]=a[++cnt];
		else for(j=n;j>=1;j--) b[j][i]=a[++cnt];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		if(b[i][j]==num) 
		{
			cout<<j<<' '<<i;
			return 0;
		}
	}
	return 0;
 }
//2 2
//99 100 97 98
//2 2
//98 99 100 97
//3 3
//94 95 96 97 98 99 100 93 92
