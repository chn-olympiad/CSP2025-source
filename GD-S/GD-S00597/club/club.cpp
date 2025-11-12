#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4];
int ans;
void sb(int x,int suma,int sumb,int sumc,int mx){
	if(suma>n/2)return;
	if(sumb>n/2)return;
	if(sumc>n/2)return;
	if(x==n+1){
		ans=max(ans,mx);
		return;
	}
	sb(x+1,suma+1,sumb,sumc,mx+a[x][1]);
	sb(x+1,suma,sumb+1,sumc,mx+a[x][2]);
	sb(x+1,suma,sumb,sumc+1,mx+a[x][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		sb(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
