#include<iostream> 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define mod 998244353
using namespace std;
int n;
int a[5005];
bool cmp(int a,int b){
	return a>b;
}
long long c(int a,int b){
	long long ans=1;
	if(b==1)return a;
	if(a==b)return 1;
	for(int i=a;i>b;i--){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<=3){
		if(a[1]<a[2]+a[3])cout<<1;
		else cout<<0;
	}
	else if(a[1]==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=mod;
		}
		cout<<ans;
	}
	else cout<<114514;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
