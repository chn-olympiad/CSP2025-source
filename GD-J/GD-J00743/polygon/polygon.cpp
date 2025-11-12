#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int n,a[5010];
long long ans;
void dg(int dp,int man,int su){
	if(dp==n){
		if(su>man*2){
			ans++;
			ans%=N;
		}
		return;
	}
	dg(dp+1,max(man,a[dp+1]),su+a[dp+1]);
	dg(dp+1,man,su);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		int x,y,z,maxn,sum=0;
		cin>>x>>y>>z;
		maxn=max(x,max(y,z));
		sum=x+y+z;
		if(sum>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dg(0,0,0);
	cout<<ans;
	return 0;
}
