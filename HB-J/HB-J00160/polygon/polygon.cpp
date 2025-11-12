#include<bits/stdc++.h>
using namespace std;
int n,a[5000],ans;
void dfs(int num,int w,int sum,int maxn){
	if(w==n){
		if(sum>maxn*2&&num>=3){
			ans++;
			return;
		}else{
			return;
		}
	}
	dfs(num+1,w+1,sum+a[w+1],a[w+1]);
	dfs(num,w+1,sum,maxn);
}
int pow(int a,int b){
	int s=a;
	for(int i=1;i<b;i++){
		s*=a;
		s%=998244353;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		int k=7;
		for(int i=4;i<=n;i++){
			k+=i;
		}
		cout<<(pow(2,n)-k)%998244353;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}
