#include<bits/stdc++.h>
using namespace std;
int n,m,now,s,c,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	int arr[n*m*1];
	for(int i = 1;i<=n*m;++i) cin >> arr[i];
	s = arr[1];
	for(int i = 1;i<n*m;++i){
		for(int j = i+1;j<n*m;++j){
			if(arr[j] > arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for(int i = 1;i<=n*m;++i) {
		if (arr[i] == s) now = i;
	}
	if(now%n == 0){
		c = now/n;
		if(c%2 == 1) r = n;
		else r = 1;
	}
	else{
		c = now/n+1;
		if(c%2 == 1) r = now%n;
		else r = n+1-(now%n);
	}
	cout << c << " " << r;
	return 0;
}

