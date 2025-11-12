#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+5;
int h[MAXN][4] = {};
int df[4][MAXN] = {};
int cnt[4] = {}, top[4] = {};

int min(int a, int b){
	return a<b?a:b;
}

int abs(int a){
	return a>0?a:-a;
}

int max(int a, int b){
	return a>b?a:b;
}

bool cmp(int a, int b){
	return a<b;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int qw;
	scanf("%d", &qw);
	while(qw--){
		for(int i = 0; i<=3; i++){
			cnt[i] = 0;
			top[i] = 0;
		}
		for(int j = 1; j<=3; j++){
			for(int i = 1; i<=MAXN-1; i++){
				df[j][i] = 0;
			}
		}
		
		int n, ans = 0;
		scanf("%d", &n);
		for(int i = 1; i<=n; i++){
			scanf("%d %d %d", &h[i][1], &h[i][2], &h[i][3]);
			int minn = 2147483647, maxn = -1, mini = -1, maxi = -1;
			for(int j = 1; j<=3; j++){
				if(h[i][j] > maxn){
					minn = maxn;
					mini = maxi;
					maxn = h[i][j];
					maxi = j;
				}
				else if(h[i][j] > minn){
					minn = h[i][j];
					mini = j;
				}
			}
			df[maxi][++top[maxi]] = maxn-minn;
			ans+=maxn;
			cnt[maxi] ++;
		}
		
		int a = cnt[1], b = cnt[2], c = cnt[3];
		int ts = max(max(a, b), c);
		if(ts>n/2){
			if(ts == a){
				sort(df[1]+1, df[1]+top[1], cmp);
				int ds = ts-n/2, k = 1;
				while(ds--){
					ans -= df[1][k++];
				}
			}
			if(ts == b){
				sort(df[2]+1, df[2]+top[2], cmp);
				int ds = ts-n/2, k = 1;
				while(ds--){
					ans -= df[2][k++];
				}
			}
			if(ts == c){
				sort(df[3]+1, df[3]+top[3], cmp);
				int ds = ts-n/2, k = 1;
				while(ds--){
					ans -= df[3][k];
					k++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


