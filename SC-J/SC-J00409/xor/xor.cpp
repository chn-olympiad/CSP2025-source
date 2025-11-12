#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long k;
long long n,a[maxn],b[maxn],v[maxn];
int ans;
void dfs(int x,int t ){
	if(x>n){
		ans=max(ans,t);
		return;
	}
	if(v[x]==k){
		t++;
		for(int i=x+1;i<=n;i++){
			v[i]=v[i]^v[x];
		}
	}
	dfs(x+1,t);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[j]=b[j];
		}
		dfs(i,0);
	}
	cout<<ans;
	return 0;
} 