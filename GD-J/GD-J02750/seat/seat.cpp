#include<bits/stdc++.h>
using namespace std;
struct score{
	int sc;
	int id;
}a[110];
bool cmp(score x,score y){
	return x.sc > y.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,sum = 0;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i].sc;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i].id == 1){
			sum = i;
			break;
		}
	}
	if(sum%n == 0){
		cout << sum/n << " ";
		if((sum/n)%2 == 0) cout << 1;
		else cout << n;
	}else{
		cout << sum/n+1 << " ";
		if((sum/n+1)%2 == 0){
			int cnt = sum%n;
			cout << n-cnt+1;
		}else cout << sum%n;
	}
	return 0;
}
