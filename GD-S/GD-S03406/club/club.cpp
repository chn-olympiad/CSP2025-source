#include <bits/stdc++.h>
using namespace std;
struct node{
	long long ok1,ok2,ok3;
	long long mx;
	long long mx_num;
}a[100010],b[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		int er = n / 2;
		if(n == 2){
			long long x,y,z,i,j,k;
			cin >> x >> y >> z >> i >> j >> k;
			cout << max((x + j), max((x + k), max((y + i), max((y + k) ,max((z + i),(z + j)))))) << endl;
		}
		else{
			for(int i=1;i<=n;i++){
				cin >> a[i].ok1 >> a[i].ok2 >> a[i].ok3;
				a[i].mx = max(a[i].ok1, max(a[i].ok2,a[i].ok3));
				if(a[i].mx == a[i].ok1){
					a[i].mx_num = 1;
				
				}
				else if(a[i].mx == a[i].ok2) {
					a[i].mx_num = 2;
				}
				else if(a[i].mx == a[i].ok3) {
					a[i].mx_num = 3;
				}
			}
			long long ans = 0;
			int club[3] = {0,0,0};
			memset(club,0,sizeof(club));
			for(int i=1;i<=n;i++){
				if(club[a[i].mx_num] < er){
					club[a[i].mx_num] ++;
					ans += a[i].mx;
				}
				if(ans <= a[i].mx){
					ans = 0;
					memset(club,0,sizeof(club));
					club[a[i].mx_num] ++;
					ans += a[i].mx;
				}
			}
			cout << ans << endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
