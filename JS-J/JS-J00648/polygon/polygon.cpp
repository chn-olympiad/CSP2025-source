#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,ma2;
long long a[5005];
long long ans;
void dg(long long c,long long m,long long w,long long sum,long long ma){
	if(c==m){
		sum+=a[w],ma=max(ma,a[w]);
		if(sum>2*ma) ans++,ans=ans%MOD;
		//cout<<c<<" "<<m<<" "<<w<<" "<<sum<<" "<<ma<<endl;
	}
	else{
		for(long long i=w+1;i<=n;i++) dg(c+1,m,w+(i-w),sum+a[w],max(ma,a[w]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i],ma2=max(ma2,a[i]);
	if(n<=3){
		if(n==3&&(a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2) cout<<1;
		else cout<<0;
		if(n<=2){cout<<0;return 0;}
	}else{
		for(long long i=3;i<=n;i++){
			for(long long j=1;j<=n-i+1;j++) dg(1,i,j,0,-1e9);
		}cout<<ans%MOD;
	}
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
