#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long a[5005],f[100005][25],sum[100005][25];
long long ans=0;
const int mod=998244353;
void srh(int k,long long summ){
	if(k==n+1){
		return ;
	}
//	if(sum+a[k]==6){
//		cout<<k<<endl; 
//	}
	f[summ+a[k]][k]++;
	srh(k+1,summ+a[k]);
	srh(k+1,summ);
}
void sol2(){
	for(int i=3;i<=n;i++){
		long long res=1;
		for(int j=1;j<=i;j++)
			res*=(n-j+1),res/=j;
		res%=mod;
		ans+=res;
		ans%=mod;
	}
	cout<<ans%mod<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long s=0;
	int fl=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>1)
			fl=1;
	}
	if(!fl){
		sol2();
		return 0;
	}
	sort(a+1,a+n+1);
	srh(1,0);
	for(int j=1;j<=n;j++){
		for(long long i=s;i>=1;i--)
			sum[i][j]=sum[i+1][j]+f[i][j],sum[i][j]%=mod;
	} 
	for(int j=1;j<=n;j++)
		for(long long i=1;i<=s;i++){
			sum[i][j]+=sum[i][j-1];
			sum[i][j]%=mod;
		}
//	cout<<f[6][4]<<endl; 
	for(int i=3;i<=n;i++){
		ans+=sum[a[i]+1][i-1];
//		cout<<sum[a[i]+1][i-1]<<endl;
		ans%=mod;
	}
	cout<<ans%mod<<endl; 
	return 0;
}
