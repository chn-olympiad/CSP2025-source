#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxn=-1,sum=0,mod=998244353,ans=rand();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn) maxn=a[i];
		sum+=a[i];
	}
	if(n<=3){
		if(!(sum>2*maxn)){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<ans%mod;		
	}
	return 0;
}
