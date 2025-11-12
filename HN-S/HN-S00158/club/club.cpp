#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T , ans;
int cnt[4];
struct nn{
	int c1_3 , c1_2;
	int c2_3 , c2_1;
	int c3_1 , c3_2;
};
nn node[N];
bool cmp1(nn x,nn y){
	int x1 = min(x.c1_2,x.c1_3) , y1 = min(y.c1_2,y.c1_3);
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp2(nn x,nn y){
	int x1 = min(x.c2_1,x.c2_3) , y1 = min(y.c2_1,y.c2_3);
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp3(nn x,nn y){
	int x1 = min(x.c3_1,x.c3_2) , y1 = min(y.c3_1,y.c3_2);
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp3_1(nn x,nn y){
	int x1 = x.c3_1 , y1 = y.c3_1;
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp3_2(nn x,nn y){
	int x1 = x.c3_2 , y1 = y.c3_2;
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp1_2(nn x,nn y){
	int x1 = x.c1_2 , y1 = y.c1_2;
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp1_3(nn x,nn y){
	int x1 = x.c1_3 , y1 = y.c1_3;
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp2_1(nn x,nn y){
	int x1 = x.c2_1 , y1 = y.c2_1;
	if(x1 < y1)return 1;
	else return 0;
}
bool cmp2_3(nn x,nn y){
	int x1 = x.c2_3 , y1 = y.c2_3;
	if(x1 < y1)return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		int n , x , y , z;
		int f1 , f2 , f3;
		cin >> n;
		memset(cnt,0,sizeof(cnt));
		memset(node,0,sizeof(node));
		ans = f1 = f2 = f3 = 0;
		for(int i = 1;i <= n;i++){
			cin >> x >> y >> z;
			if(x >= y&&x >= z){
				ans += x;
				node[++f1].c1_2 = x - y,node[f1].c1_3 = x - z;
				cnt[1]++;
			}else if(y >= x&&y >=z){
				ans += y;	
				cnt[2]++;
				node[++f2].c2_1 = y - x,node[f2].c2_3 = y - z;
			}else{
				ans += z;
				cnt[3]++;
				node[++f3].c3_1 = z - x,node[f3].c3_2 = z - y;
			}
		}
		if(cnt[1] > n / 2){
			sort(node+1,node+1+f1,cmp1);
			for(int i = 1;i <= f1;i++){
				if(node[i].c1_2 > node[i].c1_3){
					cnt[3]++,cnt[1]--;
					ans -= node[i].c1_3;
					node[++f3].c3_2 = node[i].c1_2 - node[i].c1_3;
				}else{
					cnt[2]++,cnt[1]--;
					ans -= node[i].c1_2;
					node[++f2].c2_3 = node[i].c1_3 - node[i].c1_2;
				}
				if(cnt[1] == n / 2)break;
			}
			if(cnt[2] > n / 2){
				sort(node+1,node+1+f2,cmp2_3);
				for(int i = 1;i <= f2;i++){
					cnt[3]++,cnt[2]--;
					ans -= node[i].c2_3;
					if(cnt[2] == n / 2)break;
				}
			}else if(cnt[3] > n / 2){
				sort(node+1,node+1+f3,cmp3_2);
				for(int i = 1;i <= f3;i++){
					cnt[2]++,cnt[3]--;
					ans -= node[i].c3_2;
					if(cnt[3] == n / 2)break;
				}
			}
		}else if(cnt[2] > n / 2){
			sort(node+1,node+1+f2,cmp2);
			for(int i = 1;i <= f2;i++){
				if(node[i].c2_1 > node[i].c2_3){
					cnt[3]++,cnt[2]--;
					ans -= node[i].c2_3;
					node[++f3].c3_1 = node[i].c2_1 - node[i].c2_3;
				}else{
					cnt[1]++,cnt[2]--;
					ans -= node[i].c2_1;
					node[++f1].c1_3 = node[i].c2_3 - node[i].c2_1;
				}
				if(cnt[2] == n / 2)break;
			}
			if(cnt[1] > n / 2){
				sort(node+1,node+1+f1,cmp1_3);
				for(int i = 1;i <= f1;i++){
					cnt[3]++,cnt[1]--;
					ans -= node[i].c1_3;
					if(cnt[1] == n / 2)break;
				}
			}else if(cnt[3] > n / 2){
				sort(node+1,node+1+f3,cmp3_1);
				for(int i = 1;i <= f3;i++){
					cnt[1]++,cnt[3]--;
					ans -= node[i].c3_1;
					if(cnt[3] == n / 2)break;
				}
			}
		}else if(cnt[3] > n / 2){
			sort(node+1,node+1+f2,cmp3);
			for(int i = 1;i <= f3;i++){
				if(node[i].c3_1 > node[i].c3_2){
					cnt[2]++,cnt[3]--;
					ans -= node[i].c3_2;
					node[++f2].c2_1 = node[i].c3_1 - node[i].c3_2;
				}else{
					cnt[1]++,cnt[3]--;
					ans -= node[i].c3_1;
					node[++f1].c1_2 = node[i].c3_2 - node[i].c3_1;
				}
				if(cnt[3] == n / 2)break;
			}
			if(cnt[2] > n / 2){
				sort(node+1,node+1+f2,cmp2_1);
				for(int i = 1;i <= f2;i++){
					cnt[1]++,cnt[2]--;
					ans -= node[i].c2_1;
					if(cnt[2] == n / 2)break;
				}
			}else if(cnt[1] > n / 2){
				sort(node+1,node+1+f1,cmp1_2);
				for(int i = 1;i <= f1;i++){
					cnt[2]++,cnt[1]--;
					ans -= node[i].c1_2;
					if(cnt[1] == n / 2)break;
				}
			}
		}
		cout << ans << endl;
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
