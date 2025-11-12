#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[6000]; 
bool f[6000]={false};
void dfs(int k,int sum,int maxn,int m){
	if(k>m&&sum>2*maxn){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]) {
			f[i]=!f[i];
			dfs(k+1,sum+a[i],max(maxn,a[i]),m);
			f[i]=!f[i];
		}
	} 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(1,0,0,i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
