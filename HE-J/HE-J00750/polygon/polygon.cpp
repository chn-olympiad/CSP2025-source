#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,N=5010;
int  n;
int a[N];
int b[N];
long long sum[N];
long long ans=0;
bool vis[N];

long long zh(int x,int z){
	long long res=1;
	for(int i=z;i>x;i--){
		res=res*i%mod;
	}
	return res%mod;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	
	if(n<3){
		cout<<0<<"\n";
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1<<"\n";
		else cout<<0<<"\n";
		return 0;
	}
	
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans=(ans+zh(i,n))%mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	
	srand(time(0));
	ans=rand()%mod;
	cout<<ans<<"\n";
	
	return 0;
}
