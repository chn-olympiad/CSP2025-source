#include<bits/stdc++.h>
using namespace std;
int seat[105][105], a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int k=a[1];
	sort(a+1, a+1+n*m);
	int now=m, num=1;
	for(int i=m;i>=1;i--){
		if(now%2==1){
			for(int i=n;i>=1;i--){
				seat[i][now]=a[num];
				num++;
			}
			now--;
		}else{
			for(int i=1;i<=n;i++){
				seat[i][now]=a[num];
				num++;
			}
			now--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==k){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}