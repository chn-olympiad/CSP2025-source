#include<bits/stdc++.h>
using namespace std;

const int N = 500;
long long n,a[N],ans;

long long work(int tot){
	if(tot == 3){
		return a[1]+a[2] > a[3];
	}
	int sum = 0,cnt = 0;
	for(int i = 1;i < tot;i++){
		sum += a[i];
	}
	for(int i = 1;i < tot;i++){
		if(sum - a[i] > a[tot]) cnt++;
	}
	return cnt;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;i++){
		ans += work(i);
	}
	cout << ans;
	return 0;
}
