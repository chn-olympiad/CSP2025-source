#include <bits/stdc++.h>
using namespace std;
int a[110],n,m,sc,w;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n*m;i++)cin >> a[i];
	sc = a[0];
	sort(a,a+n*m,cmp);
	for(int i = 0;i < n*m;i++){
		if(a[i]==sc)w=i+1;
	}
	cout << w/n+(w%n?1:0) << ' ';
	if(w>2*n){
		w-=(w/n+(w%n?1:0)-2)*2*n;
	}
	if(w>n){
		cout << 2*n - w+1;
	}
	else cout << w;
	return 0;
} 
