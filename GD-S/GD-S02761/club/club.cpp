#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node{
	int val,id;
} a[N][10];
int T,n,cnt[10],ans;

bool cmp(node x,node y)
{
	if(x.val == y.val) return x.id < y.id;
	return x.val > y.val;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		priority_queue <pair <int,pair <int,int> > > q[5];
		memset(cnt,0,sizeof(cnt));
		ans = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d",&a[i][j].val);
				a[i][j].id = j;
			}
			sort(a[i] + 1,a[i] + 1 + 3,cmp);
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				int p = a[i][j].id;
				if(cnt[p] + 1 <= n / 2){
					ans += a[i][j].val;
					q[p].push({a[i][j+1].val - a[i][j].val,{i,j}});
					cnt[p]++;
					break;
				}
				else{
					int num = -q[p].top().first,pos = q[p].top().second.first,id = q[p].top().second.second;
//					printf("num = %d, pos = %d, id = %d\n",num,pos,id);
					if(num <= a[i][j].val){
						q[p].pop();
						ans += a[i][j].val - num;
						cnt[a[pos][id+1].id]++;
						q[a[pos][id+1].id].push({a[pos][id+2].val - a[pos][id+1].val,{pos,id + 1}});
						q[p].push({a[i][j+1].val - a[i][j].val,{i,j}});
						break;
					}
				}
			}
//			printf("%d: ",i);for(int j = 1; j <= 3; j++) printf("%d ",cnt[j]);puts("");
//			printf("ans = %d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0

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
