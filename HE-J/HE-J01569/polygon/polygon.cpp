#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N], b[N];
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	for(int i = 1; i <= n; i++){
			int t = 0;		
		for(int j = i; j <= i+3; j++){
			b[t++] = a[j];
		}
		sort(b+1, b+n+1);
		if(b[1]+b[2] > b[3]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

