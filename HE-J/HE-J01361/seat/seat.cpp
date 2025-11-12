#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105], num;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	num = a[1];
	sort(a+1, a+n*m+1, cmp);
	int i=1, j=1, x=1;
	while(a[x]!=num){
		if(i%2){
			if(j==n) i++;
			else j++;
		}
		else{
			if(j==1) i++;
			else j--;
		}
		x++;
	}
	cout << i << ' ' << j;
	return 0;
}
