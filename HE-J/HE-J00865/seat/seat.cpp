#include<bits/stdc++.h>
using namespace std;

int n,m,a[20],ans[20][20];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> a[i];
	int k = a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(i%2 == 1){
			for(int j = 1;j <= m;j++){
				cnt++;
				ans[i][j] = a[cnt];
			}
		}else{
			for(int j = m;j >= 1;j--){
				cnt++;
				ans[i][j] = a[cnt];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(ans[i][j] == k){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
