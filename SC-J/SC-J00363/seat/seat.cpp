#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,fl=0,k;
vector<ll> ve;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=0,v;i<(n*m);i++)
	{
		cin>>v;
		ve.push_back(v);
	}
	fl=ve.front();
	stable_sort(ve.begin(),ve.end(),cmp);
	for(ll i=0;i<(ll)ve.size();i++)
	{
		if(ve[i]==fl)
		{
			k=i;
			break;
		}
	}
	cout<<(floor(k/n)+1)<<' '<<((((ll)floor(k/n))+1)%2==1?((k%n)+1):((n-(k%n))));
	return 0;
}