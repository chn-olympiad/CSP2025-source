#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long n;
long long b[50005]={},a[5005]={};
long long mod=998244353;
long long ans=0;
long long lg=0;
void todo(){
	int vis[5005]={};
	for(int i=1;i<=n;i++){
		vis[b[i]]++;
	}for(int i=1;i<=n;i++){
		if(vis[i]>1){
			return;
		}
	}long long ls=0,ls2=-1;
	for(int i=1;i<=n;i++){
		ls+=a[b[i]];
	}for(int i=1;i<=n;i++){
		ls2=max(ls2,a[b[i]]);
	}if(ls>2*ls2){
		lg++;
	}
	return;
}void dg(long long x,long long y){
	if(x>y){
		todo();
		return;
	}else{
		for(int i=1;i<=n;i++){
			b[x]=i;
			dg(x+1,y);
		}
	}return;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dg(1,i);
		long long x=1;
		for(long long j=1;j<=i;j++){
			x*=j;
		}lg/=x;
		ans+=lg;
		lg=0;
	}ans%=mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
