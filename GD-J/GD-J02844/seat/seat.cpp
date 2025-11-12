#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[110];
int g, cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	g = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++){
		if(a[i] == g){
			cnt = i;
			break;
		}
	}
	int l = cnt / n;
	int h = cnt % n;
	if(l < 1) l++;
	else if(h > 0) l++;
	if(l%2==1 && h==0){
		h = n;
	}
	if(l%2 == 0){
		if(h == 0) h = 1;
		else h = n + 1 - h;
	}
	cout << l << ' ' << h;
	return 0;
}

