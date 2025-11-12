#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
long long ans=1ll;
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	if(n<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++)ans=(ans*1ll*i)%mod;
	cout<<ans<<'\n';
	return 0;
}
