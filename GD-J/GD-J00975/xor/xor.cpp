#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
int a[maxn],s[maxn],check[maxn],c[maxn];
vector<pair<int,int>> v;
int n,k,ans=0;
void dfs(int id,int cnt){
	if(id==v.size()){
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+check[i];
			if(c[i]>=2) return;
		}
		ans=max(ans,cnt);
		return;
	}
	int l=v[id].first,r=v[id].second;
	check[l]++,check[r+1]--;
	dfs(id+1,cnt+1);
	check[l]--,check[r+1]++;
	dfs(id+1,cnt);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((s[r]^s[l-1])==k){
				v.push_back(make_pair(l,r));
			}
		}
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
