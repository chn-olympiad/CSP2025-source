#include <bits/stdc++.h>
using namespace std;
int n,m,b,r,cnt=1,co,ro;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	for(int i = 1;i <= n*m-1;i++){
		cin >> b;
		if(b > r) cnt++; 
	}
	co = cnt/n+bool(cnt%n);
	if(cnt%n != 0){
		if(co%2 == 0) ro = n-(cnt%n)+1;
		else ro += cnt%n;
	}
	else{
		if(co%2 == 0) ro = 1;
		else ro = n;
	}
	cout << co << " " << ro;
	return 0;
}
