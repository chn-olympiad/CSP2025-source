#include<bits/stdc++.h>
using namespace std;
int n;
int a[50009],ans=0;
int mod=998244353;
//
int b[50009];
void dfs(int x,int s){
	if(x>n){
		int ma=0,sum=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				ma=max(ma,a[i]);
				sum=sum+a[i];
			}
		}
		if(s>=3&&sum>ma*2){
			ans=(ans+1)%mod;
		}
		return;
	}
	b[x]=1;
	dfs(x+1,s+1);
	b[x]=0;
	dfs(x+1,s);
}
void run1(){
	dfs(1,0);
	cout<<ans;
}
//
int c[5009][5009];
void init(){
	c[0][0]=1;c[1][0]=c[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j>0)c[i][j]=(c[i][j]+c[i-1][j-1])%mod;
			c[i][j]=(c[i][j]+c[i-1][j])%mod;
		}
	}
}
void run2(){
	init();
	for(int i=3;i<=n;i++){
		ans=(ans+c[n][i])%mod;
	}
	cout<<ans;
}
//
void run3(){
	srand(time(0));
	init();
	for(int i=3;i<=n;i++)ans=(ans+c[n][i])%mod;
	int t=rand()%ans;
	cout<<ans-t;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int bj=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)bj=1;
	}
	sort(a+1,a+1+n);
	if(n<=20)run1();
	else if(bj==0)run2();
	else run3();
	return 0;
}
