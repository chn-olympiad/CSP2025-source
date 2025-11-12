#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],s[N],f[N],p[2000100],dp[N];
int read();
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
//	cin>>n>>k;
	p[0]=1;
	for(int i=2;i<=n+1;++i){
//		cin>>a[i];
		a[i]=read();
		s[i]=s[i-1] xor a[i];
		p[s[i]]=i;
		int y=k xor s[i];
		if(p[y]!=0)f[i] = f[p[y]] + 1,dp[i]=max(f[i-1],f[i]);
		else f[i]=f[i-1],dp[i]=dp[i-1];
		
//		cout<<s[i]<<" "<<f[i]<<'\n';
	}
	cout<<dp[n+1];
	return 0;
}
int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

