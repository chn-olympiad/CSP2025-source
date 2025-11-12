#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int a[1000];
bool cmp(int b,int y){
	return b > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (a[i]==x){
			int c=(i+n-1)/n;
			int d=(i-1)%n+1;
			if (c%2==1)cout << c << " " << d;
			else{
				cout << c << " " << (n+1-d);
			}
			return 0;
		}
	}
	return 0;
}
