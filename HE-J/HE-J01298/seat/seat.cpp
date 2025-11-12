#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,a[105],x,l,p=1,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat2.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    l = n*m;
    for(int i = 1;i <= l;i++) cin >> a[i];
	x = a[1];
	sort(a+1,a+l+1,cmp);
	for(int i = 1;i <= l;i++){
		if(a[i]==x)p=i;
	}
	r=(p-1)/n+1;
	cout << r << " ";
	if(r%2){
		if(p%n!=0)cout << p%n;
		else cout << n;
	}
	else{
		if(p%n!=0)cout << n-p%n+1;
		else cout << 1;
    }
    return 0;
}
