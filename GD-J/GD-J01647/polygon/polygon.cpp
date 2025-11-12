#include <bits/stdc++.h>

using namespace std;

int a[5010], n, ans;

//void out3(){
//	switch(n){
//		case 1:{
//			cout<<0;
//			break;
//		}
//		case 2:{
//			cout<<0;
//			break;
//		}
//		case 3:{
//			if(a[1] + a[2] > a[3]){
//				cout<<1;
//			}
//			else{
//				cout<<0;
//			}
//			break;
//		}
//	}
//}

void work(int fori, int ifa, int ret){
//	cout<<fori<<' '<<ifa<<' '<<ret<<endl;
	if(ret == 1){
		for(int i = fori; i <= n; i++){
			if(ifa > a[i])ans++;
		}
	}
	else{
		for(int i = fori; i < n; i++){
			work(i + 1, ifa + a[i], ret - 1);
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a + 1, a + n + 1);
//	if(n <= 3){
//		out3();
//		return 0;
//	}
//	for(int i = 1; i <= n; i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	for(int i = 3; i <= n; i++){
		work(1, 0, i);
	}
//	cout<<ans<<endl;
	cout<<(ans % 998244353);
	return 0;
}
