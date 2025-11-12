#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e5+10,mod=998244353;
long long a[MAXN];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=2)cout<<0;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a)cout<<1;
		else cout<<0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long cnt=1;
			for(int j=0;j<i;j++){
				cnt=(cnt*(n-j))%mod;
			}
			for(int j=i;j;j--){
				cnt/=j;
			}
			ans=(ans+cnt)%mod;
		}
		cout<<ans;
	}
	return 0;
}
