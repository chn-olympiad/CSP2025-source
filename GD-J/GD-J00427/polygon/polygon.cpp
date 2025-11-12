#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define mod 998244353
int a[5010],n;
ll C(int n,int m){
	int sum=1;
	for(int i=2;i<=m;i++){
		sum=sum*i%mod;
	}
	for(int i=1;i<=n;i++){
		sum=sum/i%mod;
	}
	for(int i=1;i<=m-n;i++){
		sum=sum/i%mod;
	}
	return sum;
}
int main(){
	//T4
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=3){
		int maxn=max(a[1],max(a[2],a[3]));
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>2*maxn)cout<<1;
		else cout<<0;
		return 0;
	}
	int s=a[1];
	ll sum=0;
	for(int i=2;i<=n;i++){
		if(s!=a[i]){
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		sum=(sum+C(i,n))%mod;
	}
	cout<<sum;
	return 0;
} 
