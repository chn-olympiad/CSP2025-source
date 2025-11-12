#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
const ll N=1e5+10;
ll ans[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int k=1;k<=t;k++){
		ll n;
		cin>>n;
		priority_queue<ll,vector<ll>,greater<ll> > qa;
		priority_queue<ll,vector<ll>,greater<ll> > qb;
		priority_queue<ll,vector<ll>,greater<ll> > qc;
		for(int i=1;i<=n;i++){
			ll a,b,c,s; 
			cin>>a>>b>>c;
			if(a>=b && a>=c)
			{
				ans[k]+=a;
				s=min(a-b,a-c);
				qa.push(s);
			}
			else if(c>=b && a<=c)
			{
				ans[k]+=c;
				s=min(c-b,c-a);
				qb.push(s);
			}
			else
			{
				ans[k]+=b;
				s=min(b-a,b-c);
				qc.push(s);
			}
		}
		if(qa.size()>n/2)
		{
			while(qa.size()>n/2)
			{
				ans[k]-=qa.top();
				qa.pop();
			}
		}
		else if(qb.size()>n/2)
		{
			while(qb.size()>n/2)
			{
				ans[k]-=qb.top();
				qb.pop();
			}
		}
		else if(qc.size()>n/2)
		{
			while(qc.size()>n/2)
			{
				ans[k]-=qc.top();
				qc.pop();
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
}
