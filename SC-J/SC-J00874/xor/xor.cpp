#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500005],b[500005];
struct node{
	int l,r;
};
vector<node>c;
bool all_1=true,all_0=true;
void dfs(int x,int maxx,int an){
	for(int i=x;i<(int)c.size();i++){
		if(an+(int)c.size()-i<=ans)break;
		if(c[i].l>maxx){
			dfs(i+1,c[i].r,an+1);
		}
	}
	ans=max(ans,an);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(b,0,sizeof(b));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		if(a[i]!=1){
			all_1=false;
			if(a[i]!=0){
				all_0=false;
			}
		}
	}
	if(all_1){
		if(k==0){
			cout<<n/2;
		}else if(k==1){
			cout<<n;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(all_0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		if(k==0){
			cout<<ans/2;
		}else if(k==1){
			cout<<ans;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((int)(b[j]^b[i])==k){
				c.push_back({i+1,j});
			}
		}
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}