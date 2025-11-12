#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n;
int cnt;
int a[N];
int f[N];
map<int,int> mp;
void fr(int x,int num,int sum,int maxx,int ch) {
	if(x==maxx+1) {
		mp[sum]++;
		if(sum>ch)cnt++;
		//cout<<sum<<'\n';
		return;
	}
	for(int i=num-1; i>=1; i--) {
		fr(x+1,i,sum+a[i],maxx,ch);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		mx+=a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
//	f[0]=0;
//	for(int i=1,k=0;i<=a[n]+a[n-1];i++){
//		f[i]=f[i-1];
//		k++;
//		if(i>a[k]){
//			if(k<=n)f[i]++;
//		}else k--;
//	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<'\n';
//	for(int i=1;i<=10;i++){
//		cout<<i<<' '<<f[i]<<'\n';
//	}
//	for(int i=1;i<=n;i++){
//		fr(1,0,0,i);
//	}
//	for(int i=1;i<=10;i++){
//		cout<<i<<' '<<mp[i]<<'\n';
//	}
//	for(int i=1;i<=n;i++){
//		long long w1=1,w2=1;
//		for(int j=n;j>n-i;j--)w1=(w1*j)%mod;
//		for(int j=1;j<=i;j++)w2=(w2*j)%mod;
//		f[0]+=(w1/w2)%mod;
//	}
//	//printf("%d",f[0]);
//	for(int i=1;i<=mx;i++){
//		f[i]=(f[i-1]-mp[i])%mod;
//		//cout<<f[i]<<'\n';
//	}
	int sum=0;
	for(int i=n; i>=1; i--) {
		for(int j=i-1; j>=1; j--) {
			//sum+=f[a[i]-a[j]]%mod;
			//cout<<a[i]<<' '<<a[j]<<' '<<f[a[i]-a[j]]<<' '<<sum<<'\n';
			for(int k=1; k<=n-2; k++) {
				cnt=0;
				fr(1,j,0,k,a[i]-a[j]);
				sum+=cnt;
			}
		}
	}
	cout<<sum<<'\n';
	return 0;
}
