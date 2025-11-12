#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=5e3+10,mod=998244353;
typedef long long ll;
int a[M],n;
ll ans=0;
void cal(int t,int l,int ma,int sum){
	if(t==0){
		if(sum>2*ma)ans=(ans+1)%mod;
		return ;
	}
	for(int i=l;i<=l-t+1;i++)
		cal(t-1,i,max(ma,a[i]),sum+a[i]);
	return ;
}
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3){
		if(a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[1]+a[2])
			cout<<1;
		else 
			cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)cal(i,1,0,0);
	cout<<ans;
	return 0;
}
