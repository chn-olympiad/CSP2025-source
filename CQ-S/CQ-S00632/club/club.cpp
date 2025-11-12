#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],d[4][100010],top[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t--;){
		scanf("%d",&n);
		int ans=0;
		top[1]=top[2]=top[3]=0;
		for(int i=1;i<=n;i++){
			pair<int,int>x[4];
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			x[1]={a[i],1};
			x[2]={b[i],2};
			x[3]={c[i],3};
			sort(x+1,x+3+1);
			d[x[3].second][++top[x[3].second]]=x[3].first-x[2].first;
			ans+=x[3].first;
		}
		for(int i=1;i<=3;i++){
			sort(d[i]+1,d[i]+top[i]+1);
			int x=1;
			for(;top[i]*2>n;){
				ans-=d[i][x],x++,top[i]--;
			}
		}
		printf("%d\n",ans);
	}
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
