#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int club[5][N/2];
int e[N], f[N], g[N];
int b, c, d;
int o, p, q;
int u, v, w;
int h, ans;
struct Student{
	int x, y, z;
};
Student a[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, n;
	scanf("%d", &T);
	while (T--){
		memset(a, 0, sizeof a);
		memset(e, 0, sizeof e);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		memset(club, 0, sizeof club);
		b = c = d = u = v = w = 0;
		h = 1;
		ans=0;
		scanf("%d", &n);
		for (int i=1; i<=n; i++){
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			if (a[i].x>=max(a[i].y, a[i].z)){
				ans+=a[i].x; 
				club[1][0]++;
				b++;
				club[1][b] = i;
			}else if (a[i].y>=max(a[i].x, a[i].z)){
				ans+=a[i].y;
				club[2][0]++;
				c++;
				club[2][c] = i;
			}else if (a[i].z>=max(a[i].x, a[i].y)){
				ans+=a[i].z;
				club[3][0]++;
				d++;
				club[3][d] = i;
			} 
		}
		if (club[1][0]<=n/2 && club[2][0]<=n/2 && club[3][0]<=n/2) printf("%d\n", ans);
		else{
			if (club[1][0]>n/2){
				for (int i=1; i<=b; i++){
					v++;
					w++;
					f[v] = a[club[1][i]].x-a[club[1][i]].y;
					g[w] = a[club[1][i]].x-a[club[1][i]].z;
				}
				p = n/2-club[2][0];
				q = n/2-club[3][0];
				sort(f+1, f+u+1);
				sort(g+1, g+w+1);
				while(club[1][0]-h+1>n/2){
					if(f[h]<g[h]) ans-=f[h];
					else ans-=g[h];
					h++;
				}
				printf("%d\n", ans);
			}else if(club[2][0]>n/2){
				for (int i=1; i<=c; i++){
					u++;
					w++;
					e[u] = a[club[2][i]].y-a[club[2][i]].x;
					g[w] = a[club[2][i]].y-a[club[2][i]].z;
				}
				o = n/2-club[1][0];
				q = n/2-club[3][0];
				sort(e+1, e+u+1);
				sort(g+1, g+w+1);
				while(club[2][0]-h+1>n/2){
					if(e[h]<g[h]) ans-=e[h];
					else ans-=g[h];
					h++;
				}
				printf("%d\n", ans);
			}else if(club[3][0]>n/2){
				for (int i=1; i<=d; i++){
					u++;
					v++;
					e[u] = a[club[3][i]].z-a[club[3][i]].x;
					f[v] = a[club[3][i]].z-a[club[3][i]].y;
				}
				o = n/2-club[1][0];
				p = n/2-club[2][0];
				sort(e+1, e+u+1);
				sort(f+1, f+v+1);
				while(club[3][0]-h+1>n/2){
					if(e[h]<f[h]) ans-=e[h];
					else ans-=f[h];
					h++;
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
