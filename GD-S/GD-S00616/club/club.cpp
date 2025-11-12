#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int t;
struct node{
	int v,r;
}list[100001][10];
bool cmp(node x,node y){
	return x.v > y.v;
}
int c[5];
int m[100010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		int ans = 0;
		scanf("%d",&n);
		c[1] = 0,c[2] = 0,c[3] = 0,c[4] = 0;
		for(int i = 1;i<=n;i++){
			m[i] = 0;
			scanf("%d%d%d",&list[i][1].v,&list[i][2].v,&list[i][3].v);
			list[i][1].r = 1,list[i][2].r = 2,list[i][3].r = 3;
			if(list[i][2].v > list[i][1].v&&list[i][2].v > list[i][3].v){
				swap(list[i][1],list[i][2]);
				if(list[i][2].v < list[i][3].v)swap(list[i][2],list[i][3]);
			}
			else if(list[i][3].v > list[i][1].v&&list[i][3].v > list[i][2].v){
				swap(list[i][1],list[i][3]);
				if(list[i][2].v < list[i][3].v)swap(list[i][2],list[i][3]);
			}				
			if(c[list[i][1].r] == n / 2){
				int ju = 1000000;
				int minid = 0;
				for(int j = 1;j<=i;j++){
					if(list[i][1].r != list[j][m[j]+1].r)continue;
					if(ju > list[j][1].v - list[j][2].v){
						ju = list[j][1].v - list[j][2].v;
						minid = j;
					}
				}
				c[list[minid][2].r]++;
				m[minid] = 1;
				ans-=ju;
			}
			else {
				c[list[i][1].r]++;
				m[i] = 0;
			}
			ans += list[i][1].v;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
