#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
const int mod=998244353;
inline int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return f*s;
} 
int n,m,s[N],c[N],ans,p[N];
string S;
bool check(){
	int cnt=0,C=0;
	for(int i=1;i<=n;i++){
		if(C>=c[p[i]])C++;
		else {
			if(S[i-1]=='0')C++;
			else if(S[i-1]=='1')cnt++;
		}
	}
	return cnt>=m;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>S;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)p[i]=i;
	do{
		if(check())(ans=(ans+1)%mod);
	}while(next_permutation(p+1,p+n+1));
	printf("%lld\n",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
