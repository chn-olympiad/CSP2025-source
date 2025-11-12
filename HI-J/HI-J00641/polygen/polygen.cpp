#include<bits/stdc++.h>
using namespace std;
int n;
long long a[101001];
long long mod=998244353;
long long ans;
long long cac(long long g,long long h){
	long long k=g-h+1;
	long long l1=1,l2=1;
	for(long long i=n;i>=k;i--)l1*=i;
	for(long long i=h;i>=1;i--)l2*=i;
	return l1/l2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
		for(long long i=3;i<=n;i++){
			ans=(ans+cac(n,i))%mod;
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
