#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,cnt,sum,a[N];
bool fg;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>>k;
	fg = 0;
	for(int i =1;i <= n; i++){
		int t;
		cin >>t;
		if(!fg){
			sum = t;
			fg = 1;
		}
		else{
			sum^= t;
		}
		if(sum == k){
			cnt ++;
			fg = 0;
		}
	}
	cout << cnt;
	return 0;
}
