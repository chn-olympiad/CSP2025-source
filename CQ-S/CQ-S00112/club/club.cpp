#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10; 
int T;
int n;
int zd;
int a[N][3];
int a2[N];
int s[3];
bool vis[N];
int sum;
int maxx;
inline void f(int x){
	if(x > n){
		maxx = max(maxx,sum);
		return;
	}
	for(int i = 1;i <= 3;i++){
		if(s[i] == zd) continue;
		sum += a[x][i];s[i]++;
		f(x + 1);
		s[i]--;sum -= a[x][i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);zd = n / 2;
		if(n > 200){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= 3;j++){
					if(j == 1) scanf("%d",&a2[i]);
					else scanf("%d",&a[i][j]);
				}
			}
			sort(a2 + 1,a2 + n + 1);
			for(int i = n;i >= n - zd + 1;i--) maxx += a2[i];
			printf("%d\n",maxx);
		}
		else{
			for(int i = 1;i <= n;i++) for(int j = 1;j <= 3;j++) scanf("%d",&a[i][j]);
			maxx = 0;
			f(1);
			printf("%d\n",maxx);
		}
	}
	return 0;
}
