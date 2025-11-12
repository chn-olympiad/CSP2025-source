#include<bits/stdc++.h>
using namespace std;
int n, m,a[1001],c,h,l;
bool cmp(int a,int b){
	return a > b;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n>> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
		    c=i; 
		}
	}
	l=c/n;
	if((c%n)%2==0){
		h=n-(c%n);
	}else {
		h=c%n;
	}
	cout << l << " " << h;
	return 0;
}
