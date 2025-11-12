#include<bits/stdc++.h>
using namespace std;
int n,m,f,fx,a[105];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= m*n;i++){
		if (a[i]==f){
			fx=i;
			break;
		}
	}
	if (fx%n==0){
		int fn=fx/n;
		if (fn&1){
			cout << fn << " " << n;
		}else{
			cout << fn << " " << 1;
		}
		return 0;
	}
	cout << fx/n+1 << " ";
	if ((fx/n)&1){
		cout << n-fx%n+1;
	}else{
		cout << fx%n;
	}
	return 0;
}
