#include<bits/stdc++.h>
#define int long long
const int N=1022;
using namespace std;
int n,m,a[N],yyy;
int cmp(int x,int y){return x>y;}
void dfs(int x,int y,int tot){
	if(a[tot]==yyy){
		printf("%lld %lld",y,x);
		return ;
	}
	if((y&1) && x+1>n || !(y&1) && x-1<1) dfs((y&1)?n:1,y+1,tot+1);
	else dfs((y&1)?x+1:x-1,y,tot+1);
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	yyy=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
}
