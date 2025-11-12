#include<iostream>
#include<cstdio>
using namespace std;
#define mod 998244353
#define int unsigned long long
short mul[30];
int a[5010];
int n,ans;
int inv[5010],s[5010];
void check(){
	int sum=0,maxn=0;
	for(int i=1;i<=n;i++){
		if(mul[i]==1){
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
	}
	if(sum>2*maxn)ans++;
}
void next_per(){
	mul[1]++;
	int x=1;
	while(1){
		if(mul[x]==2){
			mul[x+1]++;
			mul[x]=0;
			x++;
		}else break;
	}
//	for(int i=1;i<=n;i++)cout<<mul[i];cout<<"\n";
	check();
}
int pow(long long x){
	int a=1;
	for(int i=1;i<=x;i++)a*=2;
	return a;
}

int quick_pow(int a,int b,int p){
	int base=1;
	while(b!=0){
		if(b%2==1)base=base*a%p;
		b/=2;
		a=a*a%p;
	}
	return base;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		for(int i=1;i<=pow(n)-1;i++)next_per();
		cout<<ans;
	}else{
//		ans=0;
		for(int i=1;i<=n;i++)inv[i]=quick_pow(i,mod-2,mod);
		s[0]=1;
		for(int i=1;i<=n;i++)s[i]=s[i-1]*inv[i]%mod;
		for(int i=3;i<=n;i++){
			int u=1,d=s[i];
			for(int j=n;j>=n+1-i;j--)u=u*j%mod;
			ans=(ans+u*d)%mod;
		}
		cout<<ans;
	}
}