#include<bits/stdc++.h>
using namespace std;//开long long!
long long n,a[10010],i,ans=1;
const long long mod=998244353;
long long jie(long long n){
	long long he=1;
	for(long long p=n;p>=1;p--){
		he*=p;
		he%=mod;
	}
	return he;
}
/*求您了，给宝宝点分吧
 CCF第一！
 * CCF最强！
 * CCF引领世界！
 * CCF认证最棒！
 * CCF给分毫不吝啬！
 * I AK IOI!




*/
int main(){
	freopen("polygon.in","r",stdin);//注释删掉!
	freopen("polygon.out","w",stdout);//注释删掉!
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	for(i=n-2;i>=2;i--){
		ans+=jie(i);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
