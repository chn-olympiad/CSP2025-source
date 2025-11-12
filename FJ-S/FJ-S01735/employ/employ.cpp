#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}

const int N=510,mod=998244353;

int n,m;
int s[N],c[N];
int p[N];


signed main(){
	
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read(),m=read();
	int cnt1=0;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		s[i]=ch-'0';
		if(s[i]==1)cnt1++;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0)tot++;
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		if(cnt1==n&&tot==0)write(ans);
		else write(0);
		return 0;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)p[i]=i;
	int tim=1;
	for(int i=1;i<=n;i++)tim*=i;
	for(int i=1;i<=tim;i++){
		next_permutation(p+1,p+1+n);
		int t=0;
		for(int j=1;j<=n;j++){
			if(s[j]==0||t>=c[p[j]])t++;
		}
		if(n-t>=m)ans=(ans+1)%mod;
	}
	write(ans);
	
	return 0;
}
/*
3 2
101
1 1 2

10 10
1111111101
6 2 4 2 1 2 5 4 3 3
3 */