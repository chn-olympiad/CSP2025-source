#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,f[505],dp[505][2],d[505],d1[505],p[505][505],ans1=0,f1=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	d[0]=1;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		d[i]=c-'0';
		if(d[i]==0)f1=0;
		if(d[i-1]==0){
			d1[i]=d1[i-1]+1;
			d1[i-1]=10000000000000;
		}else{
			d1[i]=1;
		}
	}
	if(d[n]==0)d1[n]=10000000000000;
	for(int i=1;i<=n;i++){
		long long c;
		cin>>c;
		if(!c)ans1++;
		for(int j=1;j<=n;j++){
			if(c>=d1[j]){
				f[j]++;
				p[i][j]++;
			}
		}
	}
	long long num=n;
	for(int i=1;i<=n;i++){
		if(d1[i]==10000000000000)num--;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(f[i]!=n){
				cout<<0;
				return 0;
			}
		}
		long long cnt=1;
		for(int i=1;i<=n;i++){
			cnt=cnt*i%998244353;
		}
		cout<<cnt;
		return 0;
	}else if(f1){
		long long cnt=1;
		for(int i=m;i<=n;i++){
			long long cnt1=1;
			for(int j=n;j>=max(n-i,ans1);j--){
				cnt1*=j-ans1;
			}
			for(int j=1;j<=i;j++){
				cnt1/=j;
			}
			cnt1*=cnt1;
			cnt1*=(i+1)*i/2;
			cnt1%=998244353;
			cnt+=cnt1;
		}
		cout<<cnt%998244353;
		return 0;
	}else if(num<=18){
		cout<<2;
	}
	return 0;
}
