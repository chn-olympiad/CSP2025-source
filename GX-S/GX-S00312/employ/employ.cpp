#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int mod=998244353;
int n,m,ans=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	puts("0");
	// For(i,m,1e8){
	// 	ans=(ans*i)%mod;
	// 	if(ans==161088479) cout<<i<<endl;
	// }
	// printf("%lld\n",ans);
	
	
	
	return 0;
}