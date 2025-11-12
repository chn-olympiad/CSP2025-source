#include<bits/stdc++.h>
using namespace std;
int m,n;
int s,h;
int a[105];
int mp[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m*n;i ++){
		cin >> a[i];
	}
	s = 1,h = a[1];
	for(int i = 1;i <= m*n - 1;i ++){
		int d;
		d = max(a[i],a[i+1]);
		if(a[i+1] == d){
			 a[i+1] = a[i];
			 a[i] = d;
		} 
		if(a[i+1] == h) s = i+1;
	}
	if(s % 2 == 0){
		cout << s/n <<" " << (n)-s%n << "\n";
	}
	else cout << s/n+1 <<" " << s%n << "\n";
	return 0;
}
//99 100 97 98
