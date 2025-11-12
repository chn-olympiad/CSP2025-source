#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[5005];
void dfs(int i,int maxi,int sumi,int num){
	if(i!=n+1){
		dfs(i+1,a[i],sumi+a[i],num+1);
		dfs(i+1,maxi,sumi,num);
	}else{
		if(sumi>maxi*2 && num>=3){
			ans++;
			//cout << i << " " << maxi << " " << sumi << " " << num << endl;
		}else{
			//cout << i << " " << maxi << " " << sumi << " " << num << endl;
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	long long onecha[5001],ndnum=1;
	bool allone=true;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) allone=false;
	}
	sort(a+1,a+1+n);
	if(allone && n>25){
		onecha[0]=1;
		for(int i=1;i<=n;i++){
			onecha[i]=onecha[i-1]+i;
			ndnum+=onecha[i];
		}
		ans=1;
		for(int i=0;i<n;i++){
			ans*=2;
			ans%=998244353;
		}
		ans=(ans+998244353*5-ndnum)%998244353;
	}else{
		dfs(1,0,0,0);
	}
	cout << ans;
	return 0;
}
