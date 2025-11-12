#include<bits/stdc++.h>
using namespace std;

struct num{
	int v, id;
};

const int N = 1e5+11;
num a[N][3], temp[N];
int cnt[3];

bool cmpr(num q, num p){
	return q.v>p.v;
}
bool cmps(num q, num p){
	return q.v<p.v;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		memset(cnt, 0, sizeof(cnt));
		int n, maxn=0, hot=-1;
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &a[i][0].v, &a[i][1].v, &a[i][2].v);
			a[i][0].id = 0;
			a[i][1].id = 1;
			a[i][2].id = 2;
			sort(a[i], a[i]+3, cmpr);
			maxn+=a[i][0].v;
			cnt[a[i][0].id]++;
		}
		
		for(int i=0;i<3;i++){
			if(cnt[i]>n/2){
				hot = i;
				break;
			}
		}
		if(hot>=0){
			int need = cnt[hot] - n/2, y=0;
			
			for(int j=1;j<=n;j++){
				if(a[j][0].id==hot){
					temp[y].v = a[j][0].v-a[j][1].v;
					temp[y++].id = j;
				}
			}
			sort(temp, temp+y, cmps);
			for(int i=0;i<need;i++){
				maxn=maxn-temp[i].v;
			}	
		}
		
		
		printf("%d\n", maxn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
