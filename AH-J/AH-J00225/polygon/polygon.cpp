#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5010],sum[5010],cnt,maxn=100000000;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1]+a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(sum[3]>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	return 0;
}
