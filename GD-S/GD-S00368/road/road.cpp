#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10010;

struct rd{
	ll fm,to,w;
};
ll n,m,k,aa,ss,dd,kt[N],kfc[6],fa[N],ans;

vector<rd> a;
bool cmp(rd e,rd f){
	return e.w<f.w;
}
ll fd(ll n){
	if(fa[n]==n) return n;
	return fa[n]=fd(fa[n]);
}
void hb(ll n,ll m){
	fa[fd(n)]=fd(m);
}
int main(){
	ios::sync_with_stdio(false);
//	a.clear();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>aa>>ss>>dd;
		a.push_back({aa,ss,dd});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>kfc[i];
		ll tmp=-1;
		for(int j=1;j<=n;j++){
			cin>>kt[j];
			if(kt[j]==0) tmp=j;
		}
		for(int j=1;j<=n;j++){
			if(tmp==-1) break;
			if(j==tmp) continue;
			a.push_back({j,tmp,kt[j]});
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		if(fd(a[i].fm)!=fd(a[i].to)){
			ans+=a[i].w;
			hb(fd(a[i].fm),fd(a[i].to));
		}
	}
	cout<<ans;
	return 0;
} 
