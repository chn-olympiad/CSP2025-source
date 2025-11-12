#include<bits/stdc++.h>
using namespace std;
const int N=5005,P=998244353;
int n,a[N],f[N<<1],ans,mi[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;f[0]=1;mi[0]=1;
	for(int i=1;i<=5000;i++) mi[i]=2ll*mi[i-1]%P;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=0;j<=a[i];j++) s=(s+f[j])%P;
		ans=(ans+mi[i-1])%P;ans=(ans+P-s)%P;
		for(int j=5000;j>=a[i];j--) (f[j]+=f[j-a[i]])%=P;
	}
	cout<<ans;
	return 0;
}
