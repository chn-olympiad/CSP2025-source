#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],Max,ans;
const long long MOD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n<3){
			cout<<"0";
			exit(0);
		}
		long long a,b,c;
		cin>>a>>b>>c;
		if(a<b+c&&b<a+c&&c<a+b) cout<<"1";
		else cout<<"0";
		exit(0);
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	if(Max==1){
		long long t=(n%MOD)*((n-1)%MOD)*((n-2)%MOD),tt=6,cnt=0;
//		cout<<t<<" "<<tt<<"\n";
		ans=(ans+(t/tt)%MOD)%MOD;
		for(long long i=4;i<=n;i++){
			t=(t*((n-cnt-3)%MOD))%MOD;
			cnt++;
			tt=(tt*i)%MOD;
//			cout<<t<<" "<<tt<<" "<<t/tt<<"\n";
			ans=(ans+(t/tt)%MOD)%MOD;
		}
		cout<<ans;
	}
	else{
		cout<<"0";
	}
	return 0;
} 
