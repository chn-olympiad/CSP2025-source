#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=5e5+5;
lint n,k;
lint f[N];
map <lint,bool> vis;
map <lint,int> p;
lint a[N],sum[N],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	n=read(),k=read();
	vis[0]=true,p[0]=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
		lint to=sum[i]^k;
		if(vis[to]) f[i]+=f[p[to]]+1;
		p[sum[i]]=i;
		vis[sum[i]]=true;
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,f[i]);
	}
	printf("%lld\n",ans);
	return 0;
}