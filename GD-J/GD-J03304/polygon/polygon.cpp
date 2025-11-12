#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n; 
	if(n == 3){
		cin >> a>> b>> c;
		int t1 = max(max(a,b),c);
		if((a + b +c)>2*t1){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	bool f = 1;
	for(int i = 1;i <= n; i++){
		int t;
		cin>>t;
		if(t != 1){
			f = 0;
		}
	} 
	if(f){
		int sum = 0;
		for(int i = 3 ;i <= n; i++){
			int cnt = n;
			for(int j = i ;j >= 1; j--){
				cnt *= (n-j);
			} 
			sum += cnt;
		} 
		cout << sum;
	}
	return 0;
}
