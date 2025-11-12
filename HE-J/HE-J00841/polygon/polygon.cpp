#include <bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const long long MOD=998244353;
int n;
long long a[N],maxx,ans;
long long f[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(a[i],maxx);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=a[i];j++) f[maxx+1]=(f[maxx+1]+f[maxx+1-j])%MOD;
		ans=(ans+f[maxx+1])%MOD;
		for(int j=maxx;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%MOD;
			if(j>a[i+1]) ans=(ans+f[j])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
