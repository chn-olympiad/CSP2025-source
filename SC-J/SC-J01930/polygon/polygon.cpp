#include<bits/stdc++.h>
using namespace std;
const bool ts=false;
long long f[5005][202];
long long powt[5555];
long long qzh[10007];
const long long mod=998244353;
long long fpow(long long a){
	if(a<=0)return 1;
	if(a<=1)return 2;
	if(powt[a])return powt[a];
	long long x=fpow(a/2);
	if(a%2)return powt[a]=((x*x)%mod)*2%mod;
	return powt[a]=(x*x)%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	if(!ts){
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
	}
	//freopen("","w",stdout);
	int n;
	long long m=-320320320,ans=0;
	cin>>n;
	long long a[n+2];
	for(int i=1;i<=n;++i){
		cin>>a[i];
		m=max(m,a[i]);
	}
	sort(a+1,a+n+1);
	if(m<=1){
		int i;
		for(i=1;i<=n;++i){
			if(a[i]==1)break;
		}
		ans=(((long long)n-i+1)*(n-i)%mod)*(n-i-1)/6%mod;
		cout<<ans;
		return 0;
	}
    f[1][0]=1;
	for(int i=2;i<=n;++i){
		qzh[0]=0;
		f[i][0]=fpow(i-1);
	//	cout<<"qzh:";
		for(int j=0;j<=m*2+1;++j){
			qzh[j+1]=(qzh[j]+f[i-1][j])%mod;
	//		cout<<qzh[j]<<" ";
		}
	//	cout<<" dp:"<<f[i][0]<<" ";
		for(long long j=1;j<=m*2+1;++j){
			f[i][j]=(qzh[m*2+2]-qzh[max(j-a[i-1],0ll)]+mod)%mod;
	//		cout<<f[i][j]<<" ";
		}
	//	cout<<endl;
	}
	for(int i=3;i<=n;++i){
		ans+=f[i][a[i]*2];
		ans%=mod;
	}
	cout<<ans;
} 