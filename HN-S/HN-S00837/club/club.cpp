#include<bits/stdc++.h>
using namespace std;
struct s{
	int a1, a2, a3;
};
const int N = 1e5;
int a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		}
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
		for(int i = 1; i <= n; i++){
			int setisfied = max(cnt1, max(cnt2, cnt3));
			if(a[i].a1 > a[i].a2 && a[i] > a[i].a3 && a[i] < n / 2){
				cnt1++;
				sum += cnt1;
			}
			else if(a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3 && a[i].a2 < n / 2){
				cnt2++;
				sum += cnt2;
			}
			else if(a[i].a3 > a[i].a1 && a[i].a3 > a[i].a2 && a[i].a3 < n / 2){
				cnt3++;
				sum += cnt3;
			}
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
