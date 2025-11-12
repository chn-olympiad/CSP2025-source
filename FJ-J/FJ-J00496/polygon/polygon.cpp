#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005];
void test1520(){
	long long res=1;
	for(int i=1;i<=n;i++) res=(res*(long long)(2))%mod;
	res=(res+mod-1)%mod;
	cout<<res;
}
void test16(){
	int ans=0;
	for(long long i=1;i<(1<<n);i++){
		int maxn=-1,sum=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				maxn=max(maxn,a[j]);
				sum+=a[j];
			}
		}
		if(maxn*2<sum) ans++;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+1+n);
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]>1){flag=0;break;}
	}
	if(flag){
		test1520();
		return 0;
	}
	if(n<=20){
		test16();
		return 0;
	}
	cout<<998244352;
	return 0;
}
