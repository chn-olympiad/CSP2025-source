#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int a[107];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i ++){
		cin >> a[i];
	}
	int tar = a[1];
	int pos = 0;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i ++){
		if(a[i] == tar){
			pos = i;
			break;
		} 
	}
//	cout << pos << '\n';
	int x = pos / n;
	pos %= n;
	if(pos != 0) x++;
	if(pos == 0) pos = n;
	if(x % 2 == 1){
		cout << x << ' ' << pos;
	}else{
		cout << x << ' ' << n - pos + 1;
	}
	return 0;
}

