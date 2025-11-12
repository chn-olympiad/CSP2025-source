#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
int a[500005];
inline void solveB(){
	int sum=!k;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k||a[i]^sum==k){
			ans++;
			sum=!k;
		}
		else sum^=a[i];
	}
	cout<<ans;
	exit(0);
}
inline void solveC(){
	int sum=-2e9;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++,sum=-2e9;
		else if(sum==-2e9)sum=a[i];
		else if(sum^a[i]==k){
			ans++;sum=-2e9;}
		else sum^=a[i];
	}
	cout<<ans;
	exit(0);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum1=0,sum0=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==0)sum0++;
		if(a[i]==1)sum1++;}
	if(k==0&&sum1==n){cout<<n/2;return 0;}
	else if(k<=1&&sum1+sum0==n)solveB();
	else solveC();
	return 0;
}
