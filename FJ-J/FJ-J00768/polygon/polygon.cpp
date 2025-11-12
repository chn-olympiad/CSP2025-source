#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
int a[5010],v[5010];
int n,ans;
void dfs(int k,int s,int maxn){
	if(k>n){
		if(s>2*maxn){
			ans++;
			ans%=mod;
			for(int i=1;i<=n;i++){
				if(v[i]){
					cout<<i<<" ";
				}
			}
			cout<<endl;
		}
		return;
	}
	dfs(k+1,s,maxn);
	v[k]=1;
	dfs(k+1,s+a[k],max(maxn,a[k]));
	v[k]=0;
}
int jc(int n){
	int s=1;
	for(int i=1;i<=n;i++){
		s*=i;
		s%=mod;
	}
	return s;
}
int C(int m,int nn){
	return jc(n)/jc(m)*jc(n-m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=3;i<=n;i++){
			ans+=C(i,n);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
