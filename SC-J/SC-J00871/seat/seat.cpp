#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e3+5;
ll n,m;
struct node{
	ll w,ip;
	bool friend operator<(node aa,node bb)
	{
		return aa.w>bb.w;
	}
}a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
		cin>>a[i].w,a[i].ip=i;
	stable_sort(a+1,a+1+n*m);
	ll id;
	for(ll i=1;i<=n*m;i++)
		if(a[i].ip==1)
		{
			id=i;break;
		}
	ll h1,h2;
	h1=(id-1)/n;
	h2=(h1%2?(n-id+h1*n+1):id-h1*n);
	cout<<h1+1<<" "<<h2<<'\n';
	return 0;
}