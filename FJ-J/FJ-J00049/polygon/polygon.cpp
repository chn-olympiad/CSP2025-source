#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,a[5005],p=998224353;
bool flag=1;
void f(long long id,long long len,int c){
	for(int i=id+1;i<=n;i++)f(i,len+a[i],c+1);
	if(len>a[id]*2&&c>=3)ans++;
	ans%=p;
}
long long qpow(long long base,long long power){
	int val=1;
	while(power){
		if(power&1){
			val=val*base%p;
		}
		power>>=1;
		base=base*base%p;
	}
	return val;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%ld",&n);
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		if(a[i]!=1)flag=0;
	}
	if(flag){
		cout<<qpow(2,n)-n*(n-1)/2-n-1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f(i,a[i],1);
	cout<<ans%p;
	return 0;
}
