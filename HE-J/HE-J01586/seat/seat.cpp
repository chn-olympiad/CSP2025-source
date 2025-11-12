#include <bits/stdc++.h>
using namespace std;
int y[106];
void h(int s,int n){
	cout << s/n + 1;
	int oop = s/n +1;
	int iip = (s-1)%n + 1;
	cout << " ";
	if (oop % 2 == 1){
		cout << iip;
	}
	else{
		cout << n-iip+1;
	}
}
bool cmp(int a,int b){
	return a > b;
}
int main(){
	int k;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i ++){
		cin >> y[i];
	}
	k = y[1];
	sort(y+1,y+1+n*m,cmp);
	for (int i = 1; i <= n*m; i ++){
		if (y[i] == k){
			h(i,n);
			return 0;
		}
	}
	
}
