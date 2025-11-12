#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,ans1;
int a[5005];
bool flag=1;
long long jc[5005];
void init(){
	jc[0]=1;
	jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=(jc[i-1]*i)%mod;//RP++
	}
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int now,int last,int maxn){
	if(now>maxn*2) ans1++;
	if(last==n) return;
	for(int i=last+1;i<=n;i++){
		dfs(now+a[i],i,maxn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag==1){
		init();
		long long ans=0;
		long long t;
		for(int i=3;i<=n;i++){
			t=jc[n]/((jc[i]*jc[n-i])%mod);//RP++
			ans=(ans+t)%mod;//RP++
		}
		cout<<ans%mod;//RP++
	}else{
		sort(a+1,a+n+1,cmp);//RP++
		for(int i=1;i<=n-2;i++) dfs(a[i],i,a[i]);//RP++
		cout<<ans1;//RP++
	}
	return 0;
}
