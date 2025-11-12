#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int l[n * m] = {};
	for(int i = 0;i < n * m;i ++){
		cin >> l[i];
	}
	int t = l[0],idx = 0;
	sort(l,l + n * m,cmp);
	for(int i = 0;i < n * m;i ++){
		if(t == l[i]) idx = i;
	}
	int x = idx / n,y = idx % n;
	cout << x + 1 << " ";
	if(x & 1)
		cout << n - y;
	else
		cout << y + 1;
	return 0;
} 
