#include<bits/stdc++.h>
using namespace std;
int n,m;
int fesu;
int t,sum = 1,pd;
int ans;
//struct node{
//	int i;
//	int su;
//}
int a[500];
//bool cmp(node x,node y){
//	return x.su > y.su;
//}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> fesu;
	for(int i = 2;i <= n*m;i++){
		cin >> t;
		if(t > fesu){
			sum++;
		}
	}
	if(sum % n == 0){
		ans = sum / n;
		if(ans % 2 == 0){
			cout << ans << " " << 1;
		}else if(ans % 2 == 1){
			cout << ans << " " << n;
		}
	}else if(sum % n >= 1){
		ans = sum / n + 1;
		pd = sum % n;
		if(ans % 2 == 0){
			cout << ans << " " << n - pd + 1;
		}else if(ans % 2 == 1){
			cout << ans << " " << pd;
		}
	}
	return 0;
}
