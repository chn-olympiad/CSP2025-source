#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,a[N],c[N],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	c[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]*i%998244353;
	}
	if(n<=3){
		sort(a+1,a+n+1);
		if(n==3&&a[1]+a[2]+a[3]>a[3]*2)
			cout<<1;
		else
			cout<<0;
	}
	else{
		for(int i=3;i<=n;i++){
			cnt=(cnt+c[n]/c[n-i]/c[i])%998244353;
		}
		cout<<cnt;
	}
}
