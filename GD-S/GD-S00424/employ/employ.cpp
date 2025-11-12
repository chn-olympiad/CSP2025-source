#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5,mod=998244353;
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
int a[maxn],c[maxn],q[maxn],inv[maxn];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=read(),m=read();
	inv[0]=1;
	for(int i=1;i<=n;i++)inv[i]=inv[i-1]*i%mod;
	string s;
	int x;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1')a[i]=a[i-1],x++;
		else a[i]=a[i-1]+1;
	}
	int ans=1;
	for(int i=0,x;i<n;i++){
		x=read();
		c[x]++;
	}
	if(x==n||n==m||m==1)cout<<inv[n];
	for(int i=n-1;i>=0;i--){
		int x=0;
		if(s[i]=='0')continue;
		for(int j=a[i]+1;j<n;j++)x+=c[j];
		ans*=max(1,x);
		for(int i=n-1;i>a[i];i--)if(c[i]>0){c[i]--;break;}
	}
	cout<<ans%mod;
	return 0;
}
