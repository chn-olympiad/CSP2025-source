#include<bits/stdc++.h>
using namespace std;
long long ans,Sum,Max;
const long long mod=998244353;
int n,r[114514],t[114514];
//void paixu(int a[114514]){
//	for(register int i=1;i<=n;i++){
//		t[r[i]]++;
//	}
//	int cake=1;
//	for(register int i=1;i<=n;i++){
//		while(t[i]--)
//		r[cake++]=i;
//	}
//}///////////ee,bo ku mo "tong pai xu" wo wa su re ?

void solve(){
	for(register int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
//	for(register int i=1;i<=n;i++){
//		cout<<r[i];
//	}
	memset(t,114514,sizeof(t));
	for(int m=3;m<=n;m++){
		for(int i=1;i<=n;i++){
			if(i+m-1>n){
				break;
			}
			for(int j=0;j<n;j++){
			if(i+m-1+j<=n){
			Max=r[i+m-1+j]*2;
			}
			else
			continue;
			for(int k=i+m-1+j;k>=i+j;k--){
				Sum+=r[k];
			}
			if(Sum>Max){
				//cout<<Max<<" ";
				//cout<<Sum<<" ";
				ans++;
			
			}
			Sum=0;
			}
			
		}
	}
	cout<<ans%mod;
}
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
solve();
return 0;
}
