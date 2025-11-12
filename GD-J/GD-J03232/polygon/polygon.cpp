#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 998244353
using namespace std;
int n,a[5005],tp=0;
long long ans=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) tp=1;
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if(tp==0){
		ans=n;
		ans=ans*(n-1)/2%N;
		ans=ans*(n-2)/3%N;
		cout<<ans%N;
		return 0;
	}
	return 0;
}
