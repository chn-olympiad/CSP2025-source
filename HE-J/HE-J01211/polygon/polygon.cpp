#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=998244353;
int n,k;
long long a[N],b[N*1000],mx,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	mx=a[1]+a[2];
	b[0]=1;
	b[a[1]]++;
	b[a[1]+a[2]]++;
	b[a[2]]++;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=mx;j++){
			ans=(ans+b[j])%M;
		}
		//cout<<ans<<endl;
		mx+=a[i];
		for(int j=mx;j-a[i]>=0;j--){
			b[j]=(b[j]+b[j-a[i]])%M;
			//cout<<b[j]<<' ';
		}
		//cout<<endl;
	}
	cout<<ans%M;
	return 0;
}
