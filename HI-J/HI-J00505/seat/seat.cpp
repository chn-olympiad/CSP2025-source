#include <bits/stdc++.h>
using namespace std;
int a[105];
int n, m;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int nm=m*n;
	for(int i=1;i<=nm;i++){
		cin >> a[i];
	}
	int tag=a[1]; 
	sort(a+1, a+nm+1, greater<int>());
	int x=0, y=1;
	for(int i=1;i<=nm;i++){
		if(i%n==1) x++;
		if(i%n==1) y=y;
		else if(x%2==1) y++;
		else if(x%2==0) y--;
		if(a[i]==tag){
			printf("%d %d", x, y);
			return 0;
		}
	}
	return 0;
}
