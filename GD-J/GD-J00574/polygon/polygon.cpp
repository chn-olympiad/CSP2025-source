#include<bits/stdc++.h>
#define ll long long
//30min AK!!!!!!!! Too easy ~
//CSP-S RP++
using namespace std;
const ll mod=998244353;
const int M=10005,N=5005,m=10001;
ll f[2][M],ans;
int a[N],n;
void add(ll &x,ll y){x+y>=mod?x+=y-mod:x+=y;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=1,nw(1);i<=n;++i,nw^=1){
		for(int j=0;j<=m;++j)
			f[nw][j]=f[nw^1][j];
		for(int j=0;j<=m;++j){
			add(f[nw][min(j+a[i],m)],f[nw^1][j]);
			if(min(j+a[i],m)>a[i]*2)add(ans,f[nw^1][j]);
		}
	}
	printf("%lld",ans);
	return 0;
}
/* 
	我常常追忆过去......
   下一句是啥来着？
   不对，为什么我在打这些东西
   阿巴阿巴...... 
*/ 
