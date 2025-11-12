#include<bits/stdc++.h>
using namespace std;
int s[15][15];
int a[105],m,n,h,l;
int cmp(int x,int y){
	return x>y;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int num=n*m;
	for (int i=1;i<=num;i++)    cin >> a[i];
	int R=a[1];
	sort(a+1,a+num+1,cmp); 
	for (int i=1;i<=num;i++) {
		if (a[i] == R)   {
			l=(i+n-1)/n;
			if (!l%2) {
				if (i%n == 0)    h=1;
				else    h=n+1-i%n;
			}  
			else {
				if (i%n != 0)    h=n;
				else    h=i%n;
			}
		}
	}
	cout << l << ' ' << h;
	return 0;
} 
