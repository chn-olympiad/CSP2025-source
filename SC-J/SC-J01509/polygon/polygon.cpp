#include<bits/stdc++.h>
using namespace std;
long long conut=0;
int n,a[5005],maxn=0,zo=0,dp[5005],k=3;
int ch(int k){
	int p=0;
	for(int i=1;i+k-1<=n;i++){
		if(zo>2*maxn)p++;
		p%=998244353;
	}
	return p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[k]++;
	}
	if(n==3)
	{
		if(2*max(a[1],a[2],a[3])<a[1]+a[2]+a[3]){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	while(k<=n){
		conut+=ch(k);
		conut%=998244353;
		k++;
	}
	cout<<conut%998244353;
	return 0;
}