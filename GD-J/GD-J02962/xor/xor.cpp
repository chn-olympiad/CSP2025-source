#include<bits/stdc++.h>
using namespace std;
int n,k,ans,tot;
int a[500005];
map<pair<int,int>,int> mp;
bool vis[500005];
map<pair<int,int>,bool> pm;
map<int,int> b,c;
int cur;
void init(){
	for (int i=1;i<=n;i++){
		mp[{i,i}]=a[i];
		for (int j=i+1;j<=n;j++) mp[{i,j}]=mp[{i,j-1}]^a[j];
	}
}
void init2(){
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (mp[{i,j}]==k) b[++cur]=i,c[cur]=j;
		}
	}
}
void solve(int x,int y,int s){
	ans=max(ans,tot);
	for (int p=s+1;p<=cur;p++){
		int i=b[p],j=c[p];
		if (pm[{i,j}]==0){
			if ((i>=x && j<=y) || (i<=x && j>=y) || (i<=x && j>=x) || (i<=y && j>=y)) continue;
			int f=0;
			for (int k=i;k<=j;k++){
				if (vis[k]==1){
					f=1;
					break;
				}
			}
			if (f) continue;
			for (int k=i;k<=j;k++) vis[k]=1;
			pm[{i,j}]=1;
			tot++;
			solve(i,j,p);
			tot--;
			pm[{i,j}]=0;
			for (int k=i;k<=j;k++) vis[k]=0;
		}
	}	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	init();
	init2();
	solve(0,0,0);
	cout<<ans<<endl;
	return 0;
}
