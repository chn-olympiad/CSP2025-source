#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
bool f=1;
const int mod=998244353;

void dfs(int k,int maxn,int he,int x,int hh){
	if(2*maxn<he&&x>=3&&hh!=he) ans++,ans%=mod;
	if(k>n) return;
	dfs(k+1,max(maxn,a[k]),he+a[k],x+1,he);
	dfs(k+1,maxn,he,x,he);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(f){
		for(int i=3;i<=n;i++){
			for(int j=1;j+i-1<=n;j++){
				ans++;ans%=mod;
			}
		}
		cout<<ans;
	}else if(n<500){
		dfs(1,0,0,0,0);
		cout<<ans;
	}else{
		while(1) cout<<"I AK IOI\n";
	}
	return 0;
}