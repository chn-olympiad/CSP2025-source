#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

namespace FastIO{
	inline ll read(){
		ll s=0,f=1;char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}
		while('0'<=c&&c<='9'){
			s=(s<<1)+(s<<3)+c-'0';
			c=getchar();
		}
		return s*f;
	}
}
using FastIO::read;
const int M = 3003000;
const int N = 1001000; 
ll t,n,ans,m,vis[N],flg[4],nn,cnt;
struct info2{
	ll val,rksd;
}aa[4];
struct info{
	ll val,rksd,rank;
}a[M];
bool cmp(info2 x,info2 y){
	return x.val>y.val;
}
bool cmp2(info x,info y){
	return x.val>y.val;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		memset(flg,0,sizeof(flg));cnt=0,ans=0;
		n=read();m=0;
		nn=n/2;
		for(int i=1;i<=n;i++){
			aa[1].val=read(),aa[2].val=read(),aa[3].val=read();
			aa[1].rksd=1,aa[2].rksd=2,aa[3].rksd=3;
			sort(aa+1,aa+4,cmp);
			ans+=aa[2].val,a[++m]=(info){aa[1].val-aa[2].val,aa[1].rksd,i},a[++m]=(info){0,aa[2].rksd,i},a[++m]=(info){aa[3].val-aa[2].val,aa[3].rksd,i};
		}
		sort(a+1,a+1+m,cmp2);
		for(int i=1;i<=m;i++){
			if(!vis[a[i].rank]&&flg[a[i].rksd]<nn)vis[a[i].rank]=1,flg[a[i].rksd]++,cnt++,ans+=a[i].val;
			if(cnt==n)break;
		}
		cout<<ans<<'\n';
	}
	
	
	
	
	
	return 0;
}
