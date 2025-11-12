#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[150],r,pos = 1; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>> m;
	cin >>r;
	a[1] = r;
	for(int i = 2; i<= n*m; i++){
		cin >> a[i];
		if(a[i]>r) pos++;
	}
	int t = ceil(pos*1.0/n);
	int t2 = pos%n;
	cout << t<<" ";
	if(t%2 == 1){
		if(t2 == 0){
			cout << n;
		}
		else{
			cout << t2;
		}
	}
	else{
		cout << n - t2 +1;
	}
	return 0;
}
