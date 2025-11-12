#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e5+5;

int n,a[N][5];
int q[5][N],cnt[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int ttt;
	scanf("%d",&ttt);
	while(ttt--){
		cnt[3]=cnt[1]=cnt[2]=0;
		scanf("%d",&n);
		LL ans=0;
		int x,y;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]>a[i][1]) y=1,x=2;
			else y=2,x=1;
			if(a[i][3]>a[i][x]) y=x,x=3;
			else if(a[i][3]>a[i][y]) y=3;
			ans+=a[i][x];
			q[x][++cnt[x]]=a[i][x]-a[i][y];
		}
		for(int i=1;i<=3;i++){
			if(!cnt[i]) continue;
			sort(q[i]+1,q[i]+1+cnt[i]);
			int l=1;
			while(cnt[i]>n/2){
				ans-=q[i][l++];
				cnt[i]--;
			}
		}
		printf("%lld\n",ans);
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
