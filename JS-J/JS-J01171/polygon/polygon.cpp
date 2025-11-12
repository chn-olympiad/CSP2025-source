#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,minhe;
int a[5010];
int dfs(int maxx,int tmp,int cnt,long long fangan,int yixuan){//dang qian  zong he
	if(tmp>n) return fangan;
	if(tmp>=3&&(cnt+a[tmp]>maxx*2)){
		fangan=(fangan+dfs(max(maxx,a[tmp]),tmp+1,a[tmp]+cnt,(fangan+1)%mod,yixuan+1)+dfs(maxx,tmp+1,cnt,fangan,yixuan))%mod;
	}else{
		fangan=(fangan+dfs(maxx,tmp+1,cnt,fangan,yixuan))%mod;
	}
	return fangan;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	minhe=a[1]+a[2]+a[3];
	cout<<dfs(-1,1,0,0,0);
	return 0;
}
