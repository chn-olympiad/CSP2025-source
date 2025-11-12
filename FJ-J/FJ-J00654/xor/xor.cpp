#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100010],sum[100010],last,ans;
long long f(long long x,long long y){
	long long num=x;
	num^=y;
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=f(sum[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=last+1;j<=i;j++){
			if(f(sum[i],sum[j-1])==k){
				ans++,last=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
