#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
int b[1000005];
int pre[1000005];
int vis[1000005];
bool chi(int l,int r){
	for(int i=l;i<=r;i++){
		if(vis[i]==1)return 0;
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==a[i]){
			g++;
			b[g]=i;
		}
		pre[i]=pre[i-1]^a[i];
	}
	int ans=g;
	b[0]=0;
	b[g+1]=n+1;
	for(int i=0;i<=g;i++){
		int s=b[i]+1;
		int e=b[i+1]-1;
		for(int j=s;j<=e;j++){
			for(int l=s;l<=e-j+1;l++){
				int x=pre[l+j-1]^pre[l-1];
				if(x==k&&chi(l,l+j-1)){
					for(int m=l;m<=l+j-1;m++)vis[m]=1;
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
4 2
2 1 0 3
*/
/*
4 3
2 1 0 3
*/
/*
4 0
2 1 0 3
*/
//63 69 12701