//GZ - S00377 贵州省实验中学  肖彦哲
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node{
	int love,bm;
}ma[N];
Node sc[N],la[N];
bool cmp(Node x,Node y){
	return x.love > y.love;
}
bool vis[5];
int n;
int a[N][3];
int sum,cnt[5];
void find(){
	for(int i = 1; i <= n; i++){
		if(cnt[ma[i].bm] + 1 <= n / 2){
			sum += ma[i].love;
			cnt[ma[i].bm]++;
		}else if(cnt[sc[i].bm] + 1 <= n / 2){
			sum += sc[i].love;
			cnt[sc[i].bm]++;
		}else{
			sum += la[i].love;
			cnt[la[i].bm]++;
		}
	}
}
int main(){
    freopen(club.in,"w",stdin);
	freopen(club.out,"r",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		sum = 0;
		cnt[1] = 0 ,cnt[2] = 0 ,cnt[3] = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][3]){
				vis[1] = true;
				vis[2] = true;
			}else if(a[i][2]){
				vis[1] = true;
			}
			int c1 = max(a[i][1],a[i][2]);
			int c3 = min(a[i][1],a[i][2]);
			int k1 = max(c1,a[i][3]);
			int k3 = min(c3,a[i][3]);
			la[i].love = k3;
			ma[i].love = k1;
			for(int j = 1; j <= 3; j++){
				if(a[i][j] != k1 && a[i][j] != k3){
					int k2 = a[i][j];
					sc[i].love = k2;
					sc[i].bm = j;
				}
			}
			if(k1 == a[i][1]){
				ma[i].bm = 1;
			}else if(k1 == a[i][2]){
				ma[i].bm = 2;
			}else{
				ma[i].bm = 3;
			}
			if(k3 == a[i][1]){
				la[i].bm = 1;
			}else if(k1 == a[i][2]){
				la[i].bm = 2;
			}else{
				la[i].bm = 3;
			}
			for(int i = 1; i <= n; i++){
			}
		}
		if(!vis[1]){
			sort(ma + 1, ma + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++){
				sum += ma[i].love;
			}
			printf("%d\n",sum);
			break;
		}
		sort(ma + 1, ma + n + 1, cmp);
		sort(sc + 1, sc + n + 1, cmp);
		sort(la + 1, la + n + 1, cmp);
		find();
		printf("%d\n",sum);
	}
	return 0;
}
