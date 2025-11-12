#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int mmx=-1;
long long ans=0;
void dfs(int len,int l,int mx,long long cnt,int now){
	if(now==len+1){
		if(cnt>2*mx){
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	for(int i=l+1;i<=n-(len-now);i++){
		dfs(len,i,max(mx,a[i]),cnt+a[i],now+1);
	}
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmx=max(mmx,a[i]);
	}
	if(mmx==1){
		long long fz=n*(n-1)*(n-2);
		long long fm=6;
		ans=(fz/fm)%998244353;
		for(int i=4;i<=n;i++){
			fm*=i;
			fz*=(n-i+1);
			fz=fz%998244353;
			fm=fm%998244353;
			ans+=(fz/fm)%998244353;
		}
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,-1,0,1);
	}
	cout<<ans;
    return 0;
}
