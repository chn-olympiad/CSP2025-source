#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
long long n,ans=0;
long long a[N];
long long b[N];
void zuhe(){
	long long m=1;
	for(long long i=1;i<=n;i++){
		m*=2;
	}
	for(long long i=1;i<=m;i++){
		long long I=i,qwe=0,asd=0,zxc=0;
		while(I>0){
			qwe++;
			b[qwe]=I%2;
			I/=2;
		}
		if(qwe>=3){
			for(long long j=1;j<=n;j++){
				if(b[j]){
					asd+=a[j];
				}
			}
			for(long long j=n;j>=1;j--){
				if(b[j]){
					zxc=a[j];
					break;
				}
			}
			if(zxc*2<asd) ans++;
			ans%=998244353;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	zuhe();
	cout<<ans;
	return 0;
}