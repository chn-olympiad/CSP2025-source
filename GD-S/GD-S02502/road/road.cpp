#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+10,M=1e6+10;
struct aa{ll now,to,w;};
ll n,m,k,f[N],b[11],ans=1e9,sum2,sum,v[11];
vector<aa> a;
bool cmp(aa x,aa y){return x.w<y.w;}
ll find(ll x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
void fun(){
	sum=0;
	for(auto t:a){
		ll tx=find(t.now),ty=find(t.to);
		if(tx!=ty){
			if(t.now>n||t.to>n){
				if((t.now>n&&v[t.now])||(t.to>n&&v[t.to])){
					sum+=t.w;
					f[tx]=ty;
				}
			}else if(t.now<=n&&t.to<=n){
				sum+=t.w;
				f[tx]=ty;
			}
		}
	}
	ans=min(ans,sum2+sum);
}	
void dfs(int y,int x){
	if(x&&y==k) return;
	if(!x){
		fun();
		return;
	}
	for(int i=y+1;i<=k;i++){
		v[i]=1;
		sum2+=b[i];
		dfs(i,x-1);
		v[i]=0;
		sum2-=b[i];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n+k+1;i++) f[i]=i;
	for(ll i=1;i<=m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		a.push_back({x,y,z});
	}
	for(ll i=1;i<=k;i++){
		cin>>b[i];
		for(ll j=1;j<=n;j++){
			ll y;
			cin>>y;
			a.push_back({n+i,j,y});
		} 
	}
	sort(a.begin(),a.end(,cmp);
	for(ll i=0;i<=k;i++) dfs(0,i);
	cout<<ans;
	return 0;
}
