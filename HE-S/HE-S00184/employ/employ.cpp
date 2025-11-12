#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0;short f=1;char s=getchar();
	while(s<48||s>57){f=s=='-'?-1:1;s=getchar();}
	while(s>47&&s<58){x=x*10+(s&15);s=getchar();}
	return x*f;
}
const int N=5e2+5;const ll P=998244353;
int n,m,c[N],p[N],tot;ll ans;
char s[N];bitset<N>vis;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		c[i]=read();p[i]=i;
		vis[i]=s[i]-48;
	}
	do{
		tot=0;
		for(int i=1;i<=n;++i)
			if(!vis[i]||tot>=c[p[i]])++tot;
		if(n-tot>=m)++ans;
	}while(next_permutation(p+1,p+n+1));
	printf("%lld",(ans%P+P)%P);
	return 0;
}//Usami Sumireko,Violet_Detector
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
//Quick.Now.
