#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const int kMaxN=5e6+10;

int n,q,c=1,u,cnt[kMaxN],pr[kMaxN],F[kMaxN],A[kMaxN],B[kMaxN];
vector<pair<short,int>> tr[kMaxN][26];
ll ans;
vector<int>Z[kMaxN];
string a,b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b,u=1;
		for(int j=0,l;j<a.size();j++){
			l=0;
			for(auto k:tr[u][a[j]-'a']){
				if(k.first==b[j]-'a'){
					l=1;
					u=k.second;
					break;
				}
			}
			if(!l){
				tr[u][a[j]-'a'].push_back({b[j]-'a',++c}),F[c]=u,u=c,Z[j+1].push_back(c),A[c]=a[j]-'a',B[c]=b[j]-'a';
			}
		}
		cnt[u]++;
	}
	pr[1]=1;
	for(int i=1,k,l,O;i<kMaxN;i++){
		for(int j:Z[i]){
			for(O=0,k=pr[F[j]];k!=1;k=pr[k]){
				l=0;
				for(auto o:tr[k][A[j]]){
					if(o.first==B[j]){
						l=1,O=o.second;
						break;
					}
				}
				if(l){
					break;
				}
			}
			if(O){
				pr[j]=O;
			}else{
				pr[j]=1;
				if(F[j]!=1){
					for(auto o:tr[1][A[j]]){
						if(o.first==B[j]){
							pr[j]=o.second;
							break;
						}
					}
				}
			}
			cnt[j]+=cnt[pr[j]];
		}
	}
	for(int i=1,j,k;i<=q;i++){
		cin>>a>>b,j=1e9,k=ans=0;
		for(int l=0;l<a.size();l++){
			if(a[l]!=b[l]){
				k=max(k,l+1),j=min(j,l+1);
			}
		}
		u=1;
		for(int l=1,p,O;l<=a.size();l++){
			for(O=0;u!=1;u=pr[u]){
				p=0;
				for(auto q:tr[u][a[l-1]-'a']){
					if(q.first==b[l-1]-'a'){
						u=q.second,p=1;
						break;
					}
				}
				if(p){
					O=1;
					break;
				}
			}
			if(!O){
				for(auto q:tr[u][a[l-1]-'a']){
					if(q.first==b[l-1]-'a'){
						u=q.second;
						break;
					}
				}
			}
			l>=k&&(ans+=cnt[u]);
		}
		u=1;
		for(int l=j+1,p,O;l<=a.size();l++){
			for(O=0;u!=1;u=pr[u]){
				p=0;
				for(auto q:tr[u][a[l-1]-'a']){
					if(q.first==b[l-1]-'a'){
						u=q.second,p=1;
						break;
					}
				}
				if(p){
					O=1;
					break;
				}
			}
			if(!O){
				for(auto q:tr[u][a[l-1]-'a']){
					if(q.first==b[l-1]-'a'){
						u=q.second;
						break;
					}
				}
			}
			l>=k&&(ans-=cnt[u]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
