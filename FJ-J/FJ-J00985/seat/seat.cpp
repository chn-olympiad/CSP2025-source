#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int a1,int b){
	return a1 > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int x = a[1],id;
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == x){
			id = i;
		}
	}
	int l = (id + n - 1) / n,r,mod = id % n;
	if(l % 2 == 0){
		r = n - mod + 1;
	}else{
		if(mod == 0) r = n;
		else r = mod;
	}
	cout << l << " " << r;
	return 0;
}
