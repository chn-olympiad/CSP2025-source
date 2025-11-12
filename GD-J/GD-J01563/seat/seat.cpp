#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=15,N=105;
ll n,m,a[N],cnt,tmp;
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[++cnt];
		}
	}
	tmp=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]==tmp)
		{
			ll o,p;
			o=(i-1)/n+1;
			p=(i-1)%n+1;
			if(o%2==0)
			{
				p=n-p+1;
			}
			cout<<o<<" "<<p;
			return 0;
		}
	}
	return 0;
}

