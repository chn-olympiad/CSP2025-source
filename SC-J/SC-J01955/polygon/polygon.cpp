#include <bits/stdc++.h>
#define int long long
using namespace std;
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=5005,Mod=998244353;
int n;
int jc[N];
int a[N],b[N];
int f[N];
int num[N*10];
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=ans*x%Mod;
		x=x*x%Mod,y>>=1;
	}
	return ans%Mod;
}
int c(int n,int m){
	int ans1=jc[n];
	int ans2=jc[m];
	int ans3=jc[n-m];
	return ans1*ksm(ans2*ans3%Mod,Mod-2)%Mod;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return 0;
	}
	return 1;
}
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]*i%Mod;
	if(n<=20){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int mx=0,sm=0,nm=0;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					mx=max(mx,a[j]);
					sm=sm+a[j];
					nm++;
				}
			}
			if(nm>=3 && sm>2*mx) ans++; 
		}
		cout<<ans%Mod<<'\n';
		return 0;
	}
	if(check()){
		int ans=ksm(2,n)-1-n-c(n,2);
		cout<<(ans%Mod+Mod)%Mod<<'\n';
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		num[a[i]]++;
		sum+=a[i];
	}
	int ans=0;
	for(int i=1;i<=sum;i++)
		b[i]=b[i-1]+num[i];
	for(int kk=1;kk<=n;kk++){
		int mx=a[kk];
		memset(f,0,sizeof f);
		f[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=0;j--){
				if(a[i]<=mx)
					f[j]=(f[j]+f[j-a[i]])%Mod;
			}
		}
		for(int i=2*mx+1;i<=sum;i++)
			ans=(ans+f[i])%Mod;
	}
	for(int i=1;i<=sum;i++){
		for(int j=2;j<=num[i];j++){
			if(j==2){
				ans=(ans-(ksm(2,b[i]-2)-1)%Mod+Mod)%Mod;
			}else{
				ans=(ans-ksm(2,b[i]-j)+Mod)%Mod;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10


20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

千万不能写成这样了

int main(){
	// freopen("polygon.in","r",stdin);
	// freopen("polygon.out","w",stdout);
	
}

*/