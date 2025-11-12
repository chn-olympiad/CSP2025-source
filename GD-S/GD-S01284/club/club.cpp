#include<bits/stdc++.h>
#define debug 0
//debug 1 -> start debug
using namespace std;
const int N = 1e5 + 100;
struct ps{
	int c[5];
}a[N];
int x[5],dis[N];
int max(int a,int b,int c){
	return max(max(a,b),c);
}
int re(ps a){
	if(a.c[1] < a.c[2])swap(a.c[1],a.c[2]);
	if(a.c[3] < a.c[1])swap(a.c[3],a.c[1]);
	if(a.c[1] < a.c[2])swap(a.c[1],a.c[2]);
	return a.c[3] - a.c[1];
}
void the_main(){
	int T;
	cin >> T;
	while(T--){
		int n,ans = 0;
		memset(x,0,sizeof(x));
		memset(dis,0,sizeof(dis));
		memset(a,0,sizeof(a));
		cin >> n;
		for(int i = 1;i<= n;i++){
			cin >> a[i].c[1] >> a[i].c[2] >> a[i].c[3];
			ans += max(a[i].c[1] , a[i].c[2] , a[i].c[3]);
			if(a[i].c[1] >= a[i].c[2] && a[i].c[1] >= a[i].c[3])x[1]++;
			if(a[i].c[2] >= a[i].c[1] && a[i].c[2] >= a[i].c[3])x[2]++;
			if(a[i].c[3] >= a[i].c[2] && a[i].c[3] >= a[i].c[1])x[3]++;
		}
		if(x[1] <= n / 2 && x[2] <= n / 2 && x[3] <= n / 2){
			cout << ans << "\n";
			continue;
		}
		int cs,len = 1;
		if(x[1] > n / 2)cs = 1;
		if(x[2] > n / 2)cs = 2;
		if(x[3] > n / 2)cs = 3;
		for(int i = 1;i<= n;i++){
			if(max(a[i].c[1] , a[i].c[2] , a[i].c[3]) == a[i].c[cs]){
				dis[len] = re(a[i]);
				len++;
			}
		}
		sort(dis + 1,dis + len + 1);
		for(int i = 1;i<= len - n / 2;i++){
			ans -= dis[i];
		}
		cout << ans << "\n";
	}
	
}
int main(){
	#if debug == 1
	cout << "start debug\n";
	#else
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	the_main();
	#if debug != 1
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}



/*const int N = 1e5 + 100;
int T,x[5],n,p[N][5],ans,a[N];
void dfs(int w,int sum){
	if(w == n){
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i<= 3;i++){
		if(x[i] <= 0 || sum + a[w] <= ans)continue;
		x[i]--;
		dfs(w + 1,sum + p[w + 1][i]);
		x[i]++;
	}
}
void the_main(){
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i<= 3;i++)x[i] = n / 2;
		for(int i = 1;i<= n;i++){
			cin >> p[i][1] >> p[i][2] >> p[i][3];
		}
		for(int i = n;i>= 1;i--)a[i] = a[i + 1] + max(max(p[i][1],p[i][2]),p[i][3]);
		for(int i = 1;i<= 3;i++){
			x[i]--;
			dfs(1,p[1][i]);
			x[i]++;
		}
		cout << ans << "\n";
		ans = 0;
	}
}
*/
