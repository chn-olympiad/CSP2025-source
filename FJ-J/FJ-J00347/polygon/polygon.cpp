#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long n,ans=0;
void f(int s,long long sum,int num){
	if(a[s]*2<sum&&num>=3)ans=(ans+1)%998244353;
	if(s==n)return;
	for(int i=s+1;i<=n;i++){
		f(i,sum+a[i],num+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f(i,a[i],1);
	}
	cout<<ans;
}
