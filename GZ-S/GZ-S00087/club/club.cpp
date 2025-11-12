//GZ-S00087 贵阳市华师一学校 吴松阳
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node {
	int tnn[3][2];
	int cha;
} pre[maxn];
int fd(node x, int value) {
	if(x.tnn[0][0] == value) {
		return x.tnn[0][1];
	} else if(x.tnn[1][0] == value) {
		return x.tnn[1][1];
	}
	return x.tnn[2][1];
}
int t, n,maxin;
int ans = 0;
int tmp[3][2];
bool cmp_cha(node a,node b) {
	return a.cha<b.cha;
}
bool used[maxn];

int main() {
	memset(pre,0,sizeof pre);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d",&t);

	while(t--) {
		memset(pre,0,sizeof pre);
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d",&pre[i].tnn[0][0],&pre[i].tnn[1][0], &pre[i].tnn[2][0]);
			pre[i].tnn[0][1]=0,pre[i].tnn[1][1]=1,pre[i].tnn[2][1]=2;
			for(int f=0; f<3; f++) {
				for(int s=f; s<3; s++) {
					if(pre[i].tnn[f][0]<pre[i].tnn[s][0]) {
						swap(pre[i].tnn[f][0],pre[i].tnn[s][0]);
						swap(pre[i].tnn[f][1],pre[i].tnn[s][1]);
					}
				}
			}
			pre[i].cha=pre[i].tnn[0][0]-pre[i].tnn[1][0];//第一大与第二大的差值
		}
		
		int cnts[3]= {};
		maxin = n / 2;
		ans = 0;
		int c[3];
		memset(c,0,sizeof c);
		for(int i=0; i<n; i++) {
			ans+=pre[i].tnn[0][0];
			c[pre[i].tnn[0][1]]++;
		}
		
		sort(pre,pre+n,cmp_cha);
		for(int i=0; i<n; i++) {
			if(c[0]<=maxin){
				break;
			}
			if(pre[i].tnn[0][1]==0) {
				ans-=pre[i].cha;
				c[0]--;
				c[pre[i].tnn[1][1]]++;
				pre[i].cha=pre[i].tnn[1][0]-pre[i].tnn[2][0];
				int tmp0=pre[i].tnn[0][0],tmp1=pre[i].tnn[0][1];
				pre[i].tnn[0][0]=pre[i].tnn[1][0];
				pre[i].tnn[1][0]=pre[i].tnn[2][0];
				pre[i].tnn[0][1]=pre[i].tnn[1][1];
				pre[i].tnn[1][1]=pre[i].tnn[2][1];
				pre[i].tnn[2][0]=tmp0,pre[i].tnn[2][1]=tmp1;
			}
		}
		sort(pre,pre+n,cmp_cha);
		for(int i=0; i<n; i++) {
			if(c[1]<=maxin) break;
			if(pre[i].tnn[0][1]==1) {
				ans-=pre[i].cha;
				c[1]--;
				c[pre[i].tnn[1][1]]++;
				pre[i].cha=pre[i].tnn[1][0]-pre[i].tnn[2][0];
				int tmp0=pre[i].tnn[0][0],tmp1=pre[i].tnn[0][1];
				pre[i].tnn[0][0]=pre[i].tnn[1][0];
				pre[i].tnn[1][0]=pre[i].tnn[2][0];
				pre[i].tnn[0][1]=pre[i].tnn[1][1];
				pre[i].tnn[1][1]=pre[i].tnn[2][1];
				pre[i].tnn[2][0]=tmp0,pre[i].tnn[2][1]=tmp1;
			}
		}
		sort(pre,pre+n,cmp_cha);
		for(int i=0; i<n; i++) {
			if(c[2]<=maxin) break;
			if(pre[i].tnn[0][1]==2) {
				ans-=pre[i].cha;
				c[2]--;
				c[pre[i].tnn[1][1]]++;
				pre[i].cha=pre[i].tnn[1][0]-pre[i].tnn[2][0];
				int tmp0=pre[i].tnn[0][0],tmp1=pre[i].tnn[0][1];
				pre[i].tnn[0][0]=pre[i].tnn[1][0];
				pre[i].tnn[1][0]=pre[i].tnn[2][0];
				pre[i].tnn[0][1]=pre[i].tnn[1][1];
				pre[i].tnn[1][1]=pre[i].tnn[2][1];
				pre[i].tnn[2][0]=tmp0,pre[i].tnn[2][1]=tmp1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
