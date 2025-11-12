#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 4;
int t,n;
int c[N];
struct node{
	int b1,b2,b3;
}a[N];
bool cmp1(node x,node y){
	return x.b1 > y.b1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;						   
	while(t--){						   
		cin >> n;					   
		int num1 = 0,num2 =0;
		int ans = 0;
		for(int i = 1;i <= n;i++)
				cin >> a[i].b1 >> a[i].b2 >> a[i].b3;
		sort(a + 1,a + n + 1,cmp1);
		for(int i = 1;i <= n;i++){
			if(a[i].b1 >= a[i].b2 && a[i].b1 >= a[i].b3 && num1 < n / 2){
				num1++;
				ans += a[i].b1;
			}
			else if(a[i].b2 >= a[i].b1 && a[i].b2 >= a[i].b3 && num2 < n / 2){
				num2++;
				ans += a[i].b2;
			}
			else{
				ans += a[i].b3;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

