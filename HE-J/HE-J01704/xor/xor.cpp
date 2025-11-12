#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n,k,a[N],ans,tips1,tips2;

int sm(int l,int r){
	int sum = 0;
	for(int i = l;i <= r;i++){
		if(a[i] == -1) return -1;
		sum ^= a[i];
	}
	return sum;
}

void work(int s){
	int l = 1,r = s,sum = 0;
	for(int i = 1;i <= n-r+1;i++){
		if(sm(l,r) == k){
			ans++;
			for(int j = l;j <= r;j++){
				a[j] = -1;
			}
		}
		l++,r++;
	}
}

int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1) tips1 = 1;
		if(a[i] != 1&&a[i] != 0) tips2 = 1;
	}
	if(!tips1&&!k){
		cout << n/2;
		return 0;
	}
	if(!tips2){
		int cnt = 0;
		if(k == 1){
			for(int i = 1;i <= n;i++){
				if(a[i] == 1) cnt++;
			}
		}
		if(k == 0){
			for(int i = 1;i <= n;i++){
				if(a[i] == 1&&a[i+1] == 1) cnt++,a[i+1] = -1;
				if(a[i] == 0) cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		work(i);
	}
	cout << ans;
	return 0;
}
