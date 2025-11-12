#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
struct node{
	ll a,b,c;
	bool operator <(const node &x){
		ll t=max({a,b,c});
		t=t-max(max(a+b-t,b+c-t),c+a-t);
		ll tx=max({x.a,x.b,x.c});
		tx=tx-max(max(x.a+x.b-tx,x.b+x.c-tx),x.a+x.c-tx);
		return t>tx;
	}
}s[N];
ll t,n,js,cnt[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		js=0;
		cin>>n;cnt[1]=cnt[2]=cnt[3]=0;
		for(ll i=1;i<=n;i++)
			cin>>s[i].a>>s[i].b>>s[i].c;
		sort(s+1,s+1+n);
		for(ll i=1;i<=n;i++)
		{
//			cout<<s[i].a<<' '<<s[i].b<<' '<<s[i].c<<'\n';
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
				if(cnt[1]>=n/2)js+=max(s[i].b,s[i].c);
				else cnt[1]++,js+=s[i].a;
			}
			else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
				if(cnt[2]>=n/2)js+=max(s[i].a,s[i].c);
				else cnt[2]++,js+=s[i].b;
			}
			else{
				if(cnt[3]>=n/2)js+=max(s[i].b,s[i].a);
				else cnt[3]++,js+=s[i].c;
			}
//			cout<<js<<'\n';
		}
		cout<<js<<'\n';
	}
	return 0;
}