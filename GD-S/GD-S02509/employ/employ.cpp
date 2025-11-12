#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int n,m,a[501],b[501],p=998244353,s;
char c[501];
bool vis[501];
void dfs(int x=1,int ps=0,int cps=0){
	if(x>n)return;
	if(ps>=m){
		(s+=1)%=p;
		return;
	}
	if(n-cps<m||ps+b[n]-b[x-1]<m)return;
	for(int i=1;i<=n;i++){
		if(!vis[i])vis[i]=1,dfs(x+1,ps+(cps<a[i]&&c[i]=='1'),cps+!(cps<a[i]&&c[i]=='1')),vis[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	n=rd(),m=rd(),scanf("%s",c+1);
	for(int i=1;i<=n;i++)a[i]=rd(),b[i]=b[i-1]+(c[i]^48);
	sort(a+1,a+1+n,greater<int>());
	if(m>b[n]){
		cout<<0;
		return 0;
	}
	if(b[n]==n){
		s=1;
		for(int i=1;i<=n;i++)(s*=n)%=p;
		cout<<s;
		return 0;
	}
	dfs(),cout<<s;
	return 0;
}
