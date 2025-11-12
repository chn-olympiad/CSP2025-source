#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007,mod=998244353;
int n,m,mx,mi=1e9;
ll ans,sum;
int a[N];
ll C(int n,int m){
	ll a=1;
	for(int i=0;i<m;i++){
		a=a*(n-i);
	}
	return a%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	if(mx==1&&mi==1){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<(1<<n);i++){
		m=mx=sum=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				m++;
				sum+=a[j];
				mx=max(mx,a[j]);
//				cout<<a[j]<<" ";
			}
		}
//		cout<<"\n"<<sum<<" "<<mx<<endl;
		if(m<3)continue;
		if(sum>(mx<<1)){
			ans++;
			ans%=mod;
//			cout<<"Yes\n";
		}
	}
	cout<<ans;
	return 0;
}
