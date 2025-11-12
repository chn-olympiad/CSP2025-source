#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000;
int n,m,target;
int idx = 0;
int Map[N][N],a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d",&a[i]);
	}
	target = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	for(int j = 1; j <= m; j++){
		if(j % 2 == 1){
			for(int i = 1; i <= n; i++){
				Map[i][j] = a[++idx];
				if(Map[i][j] == target){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else{
			for(int i = n; i >= 1; i--){
				Map[i][j] = a[++idx];
				if(Map[i][j] == target){
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
}
