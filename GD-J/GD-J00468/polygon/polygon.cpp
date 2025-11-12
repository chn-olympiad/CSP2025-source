#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+10,mod=998244353;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int a[maxn],mp[maxn];
int fa(int a,int b){
	int ans=1;
	while(b>0){
		if(b%2==0)a=a*a%mod,b/=2;
		else ans=ans*a%mod,b--;
	}
	return ans%mod;
}
int jc[maxn];
int inv(int a,int b){
	return a*fa(b,mod-2)%mod;
}
int C(int m,int n){
	return inv(jc[n],jc[m]*jc[n-m]%mod);
}
int n,ans,m;
void dfs(int sum,int ma,int now,int pre){
	if(now==m){
		if(sum>ma*2)ans++;
		return;
	}
	for(int i=pre+1;i<=n;i++)dfs(sum+a[i],max(ma,a[i]),now+1,i); 
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	int ma=0;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		a[i]=read(),mp[a[i]]++;
		ma=max(a[i],ma);
	}
	for(int i=1;i<=ma;i++){
		if(mp[i]==n){
			int ans=0;
			for(int i=3;i<=n;i++)ans=(ans+C(i,n))%mod;
			cout<<ans;
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		m=i;
		dfs(0,0,0,0);
	}
	cout<<ans;
	return 0;
} 
