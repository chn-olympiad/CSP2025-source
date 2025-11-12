#include<bits/stdc++.h>
#define N 10005
#define M 100005
#define int long long
using namespace std;
int n,m,a[N],x=1,y=1,k=1,t;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==t)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		if(y==n&&k==1)
		{
			x++;
			k=-1;
			continue;
		}
		if(y==1&&k==-1)
		{
			x++;
			k=1;
			continue;
		}
		y+=k;
	}
	return 0;
}
/*
ji xu zheng huo
(hua shuo geany shen mi de zhu shi xi tong za hui shi a wei!
//freopen//freopen//freopen//freopen//freopen//freopen
------------------------------------------------------------
hua shuo zhe ti hao shui...
<< n<=10,m<=10 >>
*/
