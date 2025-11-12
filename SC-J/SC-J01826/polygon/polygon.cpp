#include <bits/stdc++.h>
using namespace std;
long long n;
long long A[200000];
long long mod=998244353; 
long long C(long long x,long long y){
	long long sum=1;
	if(y==x) return 1;
	for(int i=x;i>=(x-y+1);i--){
		sum=(sum*i)%mod;
	}
	long long cnt=1;
	for(int i=2;i<=y;i++){
		cnt=(cnt*i)%mod;
	}
	return sum/cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long cnt=0;
	long long mx=-1e9;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		cnt+=A[i];
		mx=max(mx,A[i]);
	}
	if(n<=2){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		if(cnt>=mx*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(mx<=1){
		cnt=0;
		for(int i=3;i<=n;i++){
			cnt=cnt+C(n,i)%mod;
		}
		cout<<cnt<<endl;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
