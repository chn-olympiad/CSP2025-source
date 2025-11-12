#include<bits/stdc++.h>
using namespace std;
const int MX=1000,INF=0x3f3f3f3f;
int a[MX];
void solve(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)  scanf("%d",&a[i]);
	int cnt=0;
	for(int i=2;i<=n*m;i++)cnt+=a[i]>a[1];
	int x,y;
	x=cnt/n+1;y=(x%2==0)?((cnt-1)%n+1):(m-((cnt-1)%n+1)+1);
	printf("%d %d",x,y);
    return ;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int T=1;
    while(T--)  solve();
    return 0;
}
