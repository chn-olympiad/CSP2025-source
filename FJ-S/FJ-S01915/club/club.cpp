#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][5];
int f[N]; 
bool cmp(int x,int y){
	if(x != y){
		return x > y;
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));		
//		for(int i = 1; i <= 3; i++){
//			sum[i] = 0;
//		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d",&a[i][j]);
			}
		}
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;//负数个数； 
		for(int i = 1; i <= n; i++){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				cnt1++;
			}else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				cnt2++; 
			}else if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1]){
				cnt3++;
			}
		}
		int k = 0;
		if(cnt1 >= cnt2 && cnt1 >= cnt3){
			k = 1;
		}else if(cnt2 >= cnt1 && cnt2 >= cnt3){
			k = 2;
		}else if(cnt3 >= cnt1 && cnt3 >= cnt2){
			k = 3;
		}
		for(int i = 1; i <= n; i++){
			if(k == 1){
				f[i] = max(a[i][2],a[i][3]);
			}else if(k == 2){
				f[i] = max(a[i][1],a[i][3]);
			}else if(k == 3){
				f[i] = max(a[i][1],a[i][2]);
			}
			f[i] -= a[i][k];
		}
		sort(f + 1,f + n + 1,cmp);
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			ans += a[i][k];
		}
		for(int i = 1; i <= n / 2;i++){
			ans += f[i]; 
		}
		int l = n / 2 + 1;
		while(f[l] > 0){
			ans += f[l];
			l++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
