#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, sum1 = 0, sum2 = 0, sum3=0, cnt = 0;
		cin >>n;
		while(n--){
			for(int i =0;i<3;i++){
				cin >> a[i];
			}
			if(a[0] >=a[1] && a[0] >a[2]){
				sum1 ++;
				cnt += a[0];
			}else if(a[1] >a[0] && a[1] >= a[2]){
				sum2 ++;
				cnt += a[1];
			}else if(a[2] >= a[0] && a[2] > a[1] ){
				sum3 ++;
				cnt += a[2];
			}
			}
			if(sum1 <= n/2 && sum2 <=n/2 && sum3 <= n/2){
				cout << cnt <<"\n";
			}
			
	}
	return 0;
}
