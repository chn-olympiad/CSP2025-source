#include<algorithm>
#include<iostream>
using namespace std;
const int N=5005,mod=998244353;
int n,ans,a[N],POW[N]={1},f[N][N];
bool vis[N][N];
int F(int n,int len){
	if(len<0)return POW[n];
	if(n==0)return 0;
	if(n==1)return (a[1]>len);
	if(vis[n][len])return f[n][len];
	vis[n][len]=true;
	return f[n][len]=(F(n-1,len)+F(n-1,len-a[n]))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],POW[i]=POW[i-1]*2%mod;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ans=(ans+F(i-1,a[i]))%mod;
	cout<<ans;
	return 0;
}
