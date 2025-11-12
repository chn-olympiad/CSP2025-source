#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=1e2+10;
int n,m,a[N],h,l;
bool cmp(int n1,int n2){
	return n1>n2;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1; i <= n*m; i ++){
		cin >> a[i];
	}
	int r=a[1];
	int rs;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i <= n*m; i ++){
		if(a[i] == r){
			rs=i;
			break;
		}
	}
	h=rs/n+1;
	int x=rs%n;
	if(x == 0){
		x=n;
		h-=1;
	}
	if(h % 2 == 0){
		l=n-x+1;
	}else{
		l=x;
	}
	cout << h << " " << l;
	return 0;
}
