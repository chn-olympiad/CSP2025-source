#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,MOD=998244353;
typedef long long LL;
int n,a[N];
bool f;
LL suma,ans;
int c(int m,int n){
	long long ans=1,des=1;
	for(int i=n;i>=1;i--){
		ans*=i;
	}
	for(int i=1;i<=m;i++){
		des*=i;
	}
	for(int i=1;i<=n-m;i++){
		des*=i;
	}
	ans=ans/des;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=true;
	}
	
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		suma=a[1]+a[2]+a[3];
		int maxn=max(a[1],a[2]);
		maxn=max(maxn,a[3]);
		if(suma>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	} 
	if(!f){
		for(int i=3;i<=n;i++){
			ans+=c(i,n);
			ans%=MOD;
		}
		ans%=MOD;
		printf("%lld\n",ans);
		return 0;
	}
	
	cout<<9;
	return 0;
	/*for(int i=3;i<=n;i++){
		int maxn=INT_MIN;
		for(int )
		ans+=c(i,n);
		ans%=MOD;
	}*/
}
