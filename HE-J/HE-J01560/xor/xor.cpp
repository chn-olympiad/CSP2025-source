#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
bool vis[MAXN];
int n,k;
int quan(int l,int r){
	int jg=a[l];
	for(int i=l+1;i<=r;i++){
		if(vis[i]==1) return -1;
		jg = jg^a[i];
	}
	return jg;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(quan(i,j)==k){
				ans++;
				for(int t=i;t<=j;t++) vis[t]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
