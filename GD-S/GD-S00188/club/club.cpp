#include<bits/stdc++.h>
using namespace std;


int t,n,a[100005][6],s[4],d=0,cnt=0;
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j] > a[i][4]){
					a[i][4] = a[i][j];
					a[i][5] = j;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			s[a[i][5]]++;
			cnt+=a[i][4];
		}

		for(int z = 1;z <= 3;z++){
			for(int i = 1;i <= 3;i++){
				if(!(s[i] <= n / 2)){
					s[i]--;
					cnt-=a[i][4];
					for(int j = 1;j <= 3;j++){
						if(d < a[i][j] && a[i][j] != a[i][4] && s[j] <= n / 2){
							s[j]++;
							cnt+=a[i][j];
							break;
						}
					}
				}
			}
		}
		cout << cnt << endl;
		cnt = 0,d = 0;
		for(int i = 1;i <= n;i++){
			s[i] = 0;
			for(int j = 1;j <= 5;j++){
				a[i][j] = 0;
			}
		}
	}
	return 0;
}
