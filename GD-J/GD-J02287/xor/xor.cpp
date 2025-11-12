#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m;
ll a[N];
ll ma;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll s=0;
		for(int j=1;j<i;j++)
		{
			if(a[j]==m)s++;
		}
		ll po=0;
		for(int j=i;j<=n;j++)
		{
			po=(po^a[j]);
			if(po==m)
			{
				s++;
				po=0;
			}
		}
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}

