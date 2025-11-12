#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int pow2[10000]={1,0},sum[10000],a[10000],n,ans;
int main(){
	//freopen("polygon1.in","r",stdin);//´óÑùÀý
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);  cout.tie(0);
	ios::sync_with_stdio(false);  

	for(int i=1;i<=5000;i++){
		pow2[i]=(2ll*pow2[i-1])%mod;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]+sum[i])%mod; 
	}
	for(int i=1;i<=n;i++){
		int j=1;
		while(sum[j]<a[i])j++;
		ans=(ans+((pow2[j]-1-j)%mod)-((pow2[i-1])%mod))%mod;
	}
	cout<<(ans%mod)<<endl;
	return 0;
}
