//为什么要攀登？因为山就在那里。 
#include<bits/stdc++.h>
#define mrx 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
inline int read(){
	int num=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar(); 
	}
	return num*flag;
}
char wshthxdsdg[40];
inline void write(int num){
	int flag=0;
	if(!num) return putchar('0'),void();
	if(num<0) putchar('-'),num=-num;
	while(num){
		wshthxdsdg[++flag]=((num%10)^48);
		num/=10;
	}
	for(int i=flag;i;i--) putchar(wshthxdsdg[i]);
}
inline void out(int num){
	write(num);
	putchar(' ');
}
inline void print(int num){
	write(num);
	putchar('\n');
}
inline int ksm(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
const int mod=998244353;
int n,m;
string s;
int c[510];
int a[100];
int ans;
int flag=1;
bool check(){
	int now=0,num=0;
	for(int i=1;i<=n;i++){
		if(now>=c[a[i]]){
			now++;
			continue;
		}
		if(s[i]=='0') now++;
		else num++;
	}
	return num>=m;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++) if(s[i]!='1') flag=0;
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=10){
		int num=1;
		for(int i=1;i<=n;i++) a[i]=i,num=num*i;
		while(num--){
			if(check()) ans++;
			next_permutation(a+1,a+n+1);
		}
		write(ans%mod);
		return 0;
	}
	if(flag){
		
	}
	return 0;
}
/*

*/
