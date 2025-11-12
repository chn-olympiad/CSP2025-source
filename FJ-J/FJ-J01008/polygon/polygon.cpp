#include<iostream>
#include<algorithm>
using namespace std;
#define mod (998244353)

int f[5010][10010];
int a[5010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0]=1;
	a[n+1]=a[n];
	int ans=1,sum=1;
	for(int i=1;i<=n;i++){
		for(int j=a[n]*2;j+1;j--){
			f[i][j]=f[i-1][j];
			if(j>=a[i])f[i][j]+=f[i-1][j-a[i]];
			if(j>=a[i]&&j<=a[i]*2)ans+=f[i-1][j-a[i]];
			f[i][j]%=mod;
			ans%=mod;
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
//			if(j>=a[i])cout<<"[ans] "<<i<<" "<<j<<" "<<f[i-1][j-a[i]]<<"\n";
		}
//		cout<<ans<<"\n";
		sum*=2;
		sum%=mod;
	}
	cout<<(sum+mod-ans)%mod;
}
