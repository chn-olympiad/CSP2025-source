#include<bits/stdc++.h> 
using namespace std;
const int MOD = 998244353,N=5100;
int a[N],n,ans;//9:40-10:59
//jy[N][N];
//int can(int rid,int radd,int maxs){
//	if(jy[rid][radd]/*web y.suanst.com*/!=0) return jy[rid][radd];
//	if(rid == 0) return (radd>maxs*2?1:0);
//	int ans=0;
//	for(int i = rid-1;i>=0;i++){
//		int kkk1 = can(i,radd,maxs);
//		int kkk2 = can(i,radd+a[i],maxs);
//		ans+=kkk1+kkk2;
//	}
//	return jy[rid][radd]=ans;
//}
int maxss = 0;
int get(int k){
	int ans = 0;
	maxss = 0;
	for(int i = 0;i<n;i++){
		if(k&(1<<i)){
			ans+=a[i];
			maxss = max(maxss,a[i]);
		}
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool one = 1;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			one=0;
		}
	}
	if(one){
		long long llans = 1;
		for(int i=0;i<n;i++){
			llans*=2;
			llans%=MOD;
		}
		cout<<((llans)-1ll*(n+1)*n/2-1)%MOD;
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<(1<<n);i++){
		int anss = get(i);
		if(maxss*2<anss){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
