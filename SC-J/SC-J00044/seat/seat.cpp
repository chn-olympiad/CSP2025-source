#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,t;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int j = 1;
	int l = 0;
	
	for(int i = 1;i <= m;i++){
		bool fl;
		if(i % 2 == 0) fl = 0,j = n;
		else fl = 1,j = 1;
		for(;j >= 1 && !fl;j--){
//			cout << " " << i << " " << j << " \n";
			l++;
			if(a[l] == t){
				cout << i << " " << j;
				return 0;
			}
		}
//		l--,j--;
		for(;j <= n && fl;j++){
//			cout << l << " " << i << " " << j << "\n";
			l++;
			if(a[l] == t){
				cout << i << " " << j;
				return 0;
			}
		}
	}
//	for(int i = 1;i <= m * n;i++){
//		cout << a[i] << " ";
//	}
	return 0;
}