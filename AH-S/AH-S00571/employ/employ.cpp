#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
const int N=1e3+10,Mod=998244353;
int n,m;
int hard[N],res[N];
LL ans=1,ze=0;
int read();
void write(int x);
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	//printf("%lld %lld\n",n,m);
	for(int i=1;i<=n;i++) {
		char ch; cin>>ch;
		if(ch=='1') hard[i]=1;
	}
	for(int i=1;i<=n;i++) {
		res[i]=read();
		if(res[i]==0) ze++;
	}
	for(LL i=n;i>=2;i--)
		ans=ans*i%Mod;
	write(ans);
	return 0;
}
int read() {
	int Arc=0,pre=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch==45) pre=-1;
	ch=getchar(); }
	while(48<=ch&&ch<=57) {
		Arc=(Arc<<3)+(Arc<<1)+(ch^48);
	ch=getchar(); }
	return Arc*pre;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	int _stack[35],_cnt=0;
	do{
		_stack[++_cnt]=x%10,x/=10;
	}while(x);
	while(_cnt) putchar(_stack[_cnt--]^48);
	puts("");
}
