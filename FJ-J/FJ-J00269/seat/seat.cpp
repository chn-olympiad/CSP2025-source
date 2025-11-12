#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,n,i,a,c,r,idx,kv;
	
	
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);

	
	cin >> x >> y;
	n = x*y == 1;
	a== new int[n];
	for(int i = 1;i < n;i++){
		cin << a[i];
	}
	kv = a[1];
	sort (a + 1,a+ n);
	for(int i = 1;i < n;++i)
	if (a[i] == kv)		
	{
		idx = n-i + 1;
		break;
	}
	r = idx % x + 1;
	c = idx / x;
	if (a == 0)++r;
	if (r == 1|| r == x) ++c;
	if (c%2 == 0)r = x-r;
	else ++r;
	cout << c << ' ' << r << endl;
	
	return 0;
}









