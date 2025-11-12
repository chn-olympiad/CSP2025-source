#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,f[5],ans,flg[N][5];
struct Node{
	int d1,d2,d3,mx;
	bool operator<(const Node nn)const{
		return mx>nn.mx;  
	}
}nod[N];
void dfs(int sum,int k){
	if(k>n){
		ans=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		int x;
		if(i==1) x=nod[k].d1;
		if(i==2) x=nod[k].d2;
		if(i==3) x=nod[k].d3;
		if(f[i]==n/2) continue;
		if(flg[k][i]>sum+x) continue;
		f[i]++;
		dfs(sum+x,k+1);
		f[i]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(flg,0,sizeof(flg));
		memset(f,0,sizeof(f));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&nod[i].d1,&nod[i].d2,&nod[i].d3);
		sort(nod+1,nod+n+1);
		dfs(0,1);
		printf("%d",ans);
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
