#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n,m,R;
int a[101],s[15][15];

int main(){
	int sh,c,r;
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++) cin>>a[i];
	R = a[1];
	sort(a+1,a+n*m+1);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == R){
			sh = n*m - i+1;
			break;
		}
	}
	c = (sh-1) /n + 1;
	if(c % 2) r = (sh-1) % n + 1;
	else r = n - (sh-1) % n; 
	cout<<c<<" "<<r;
	return 0;
}
