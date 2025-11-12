//20-30pts 
//wo men zai lao shi de yan li jiu shi yi tuo qian!
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+111;
int n;
struct pai{
	int x,id;
}a[N][6];
int cnt[N];
long long maxx=-0x3f3f3f3f;
void dfs(int k,long long sum){
	if(k==n+1){
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[a[k][i].id]+1>n/2){
			continue;
		}
		cnt[a[k][i].id]++;
		dfs(k+1,sum+a[k][i].x);
		cnt[a[k][i].id]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		maxx=-0x3f3f3f3f;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j].x);
				a[i][j].id=j;
			}
			if(a[i][1].x<a[i][2].x){
				swap(a[i][1],a[i][2]);
			}
			if(a[i][2].x<a[i][3].x){
				swap(a[i][2],a[i][3]);
			}
			if(a[i][1].x<a[i][2].x){
				swap(a[i][1],a[i][2]);
			}
		}
		dfs(1,0);
		printf("%lld\n",maxx);
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
