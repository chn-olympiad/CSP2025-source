#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,s1,s2,s3,ans,t1,t2,t3;
bool vis[100010];
vector<pair<ll,ll>>a;
vector<pair<ll,ll>>b;
vector<pair<ll,ll>>c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		a.clear();
		b.clear();
		c.clear();
		ans=0;
		s1=0;
		s2=0;
		s3=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>t1>>t2>>t3;
			a.push_back({t1,i});
			b.push_back({t2,i});
			c.push_back({t3,i});
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		while(s1+s2+s3<n){
			ll maxn=0;
			maxn=max(a[a.size()-1].first,max(b[b.size()-1].first,c[c.size()-1].first));
			if(s1==n/2){
				maxn=max(b[b.size()-1].first,c[c.size()-1].first);
			}
			if(s2==n/2){
				maxn=max(a[a.size()-1].first,c[c.size()-1].first);
			}
			if(s3==n/2){
				maxn=max(a[a.size()-1].first,b[b.size()-1].first);
			}
			if(maxn==a[a.size()-1].first){
				if(s1<n/2){
					if(!vis[a[a.size()-1].second]){
						++s1;
						vis[a[a.size()-1].second]=1;
						ans+=a[a.size()-1].first;
						a.pop_back();
					}
					else{
						a.pop_back();
					}
				}
				if(s1+s2+s3>=n){
					break;
				}
			}
			if(maxn==b[b.size()-1].first){
				if(s2<n/2){
					if(!vis[b[b.size()-1].second]){
						++s2;
						vis[b[b.size()-1].second]=1;
						ans+=b[b.size()-1].first;
						b.pop_back();
					}
					else{
						b.pop_back();
					}
				}
				if(s1+s2+s3>=n){
					break;
				}
			}
			
			if(maxn==c[c.size()-1].first){
				if(s3<n/2){
					if(!vis[c[c.size()-1].second]){
						++s3;
						vis[c[c.size()-1].second]=1;
						ans+=c[c.size()-1].first;
						c.pop_back();
					}
					else{
						c.pop_back();
					}
				}
				if(s1+s2+s3>=n){
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
