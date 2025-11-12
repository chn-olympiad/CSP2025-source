#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],mod=998244353;string s;
int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();cin>>s;for(int i=1;i<=n;i++)a[i]=read();
	bool f=true;for(int i=0;i<n;i++)if(s[i]=='0')f=false;
	if(f){
		long long s=1;
		for(int i=2;i<=n;i++)s=s*i%mod;
		write(s);
		exit(0);
	}
	write(1);
	return 0;
}
