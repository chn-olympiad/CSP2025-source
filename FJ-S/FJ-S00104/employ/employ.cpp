#include<bits/stdc++.h>
#define N 505
using namespace std;
const int mod=998244353;
inline long long read(){
	long long x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
long long n,m,c[N],cnt,fac[N];
string a;
bool cha=1;
int main(){
//	freopen("employ1.in","r",stdin);
//	freopen("employ1.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=500;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	n=read(),m=read();
	cin>>a;
	a=" "+a;
	for(int i=1;i<=n;i++){
		if(a[i]!='1')cha=0;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		cnt+=(c[i]==0);
	}
	if(cha){
		if(n-cnt>=m){
			cout<<fac[n]%mod;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
}

