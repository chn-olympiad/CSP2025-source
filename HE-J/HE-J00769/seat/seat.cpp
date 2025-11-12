#include<bits/stdc++.h>
using namespace std;

int a[105];
int ans,num;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
		if(a[1] == n * m)
		cout << 1 << " " << 1; 
		if(a[1]==1)
		cout << m << " " << n; 
		int cnt = a[1];
		for(int i = 1; i<=m*n;i++){
			for(int j=i; j<=m*n;j++){
				if(a[i]<a[j])
				swap(a[i],a[j]);
			}
		}
		for(int i = 1; i <= n * m; i++)
			if(a[i] == cnt){
			ans = i;
			num = ans / n;
			if(ans % n != 0 )
			num++;
		}
			if(ans % (2 * n) <= n && ans % (2 * n) > 0)
			cout << num << " " << ans - ((num-1) * n); 
			else if(ans % (2 * n) > n || ans % (2 * n) == 0)
			cout << num << " " << n - (ans - ((num-1) *n)-1);
}
