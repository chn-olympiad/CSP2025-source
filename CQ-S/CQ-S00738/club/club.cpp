#include<bits/stdc++.h>
namespace cxk{
	using namespace std;
	#define ll long long
	ll t,n,sm[5],ans;
	struct node{
		pair<ll,ll>v[4];
		bool operator<(node x)const{return v[1].first>x.v[1].first;}
	}a[100005];
	priority_queue<ll,vector<ll>,greater<ll> >q[4];
	int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(nullptr);
		cout.tie(nullptr);
		cin>>t;
		while(t--){
			ans=0;
			for(int i=1;i<=3;i++){
				while(q[i].size())q[i].pop();
				sm[i]=0;
			}
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>a[i].v[1].first>>a[i].v[2].first>>a[i].v[3].first;
				a[i].v[1].second=1;
				a[i].v[2].second=2;
				a[i].v[3].second=3;
				sort(a[i].v+1,a[i].v+4,greater<pair<ll,ll> >());
			}
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++){
				pair<ll,ll>x=a[i].v[1],y=a[i].v[2];
				ans+=x.first;
				q[x.second].push(x.first-y.first);
				if(sm[x.second]==n/2){
					ans-=q[x.second].top();
					q[x.second].pop();
				}else sm[x.second]++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main(){return cxk::main();}
