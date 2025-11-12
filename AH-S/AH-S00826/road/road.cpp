#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;register char ch=getchar_unlocked();
	while(ch<'0'||'9'<ch){if(ch=='-') f=-f; ch=getchar_unlocked();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar_unlocked();}
	return x*f;
}
const int N=1e4+5,oo=1e9;
int c[15],mn[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	register int n=read(),m=read(),k=read(),i,j,flag=1;
	register long long ans=0,mns=oo;
	for(i=1;i<=m;++i)
		register int u=read(),v=read(),w=read();
	for(i=1;i<=n;++i) mn[i]=oo;
	for(i=1;i<=k;++i){
		c[i]=read();
		if(c[i]) flag=0;
		register long long now=c[i];
		for(j=1;j<=n;++j){
			register int x=read();
			now+=x;
			mn[j]=min(mn[j],x);
		}
		mns=min(mns,now);
	}
	if(flag){
		for(i=1;i<=n;++i) {
			ans+=mn[i];
			//printf("%d\n",mn[i]);
		}
		printf("%lld\n",ans);
	}
	else printf("%lld\n",mns);
	return 0;
}
