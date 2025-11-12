#include<bits/stdc++.h>
using namespace std;
int t,n,a[100009][3],ois[100009],cnt[3],ans;
int l[100009],cntl;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans = 0;
		cnt[0] = cnt[1] = cnt[2] = cntl = 0;
		for(int i = 1; i <= n; i ++){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
				ois[i] = 0;
				ans += a[i][0];
				cnt[0] ++;
			}
			else if(a[i][1] >= a[i][2]){
				ois[i] = 1;
				ans += a[i][1];
				cnt[1] ++;
			}
			else{
				ois[i] = 2;
				ans += a[i][2];
				cnt[2] ++;
			}
		}
		for(int j = 0; j < 3; j ++){
			if((cnt[j] << 1) > n){
				for(int i = 1; i <= n; i ++){
					if(ois[i] == j){
						l[++cntl] = min(a[i][j] - a[i][(j + 1) % 3],a[i][j] - a[i][(j + 2) % 3]);
					}
				}
				sort(l + 1,l + cntl + 1);
				for(int i = 1; i <= cnt[j] - (n >> 1); i ++){
					ans -= l[i];
				}
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
