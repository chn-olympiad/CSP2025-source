#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n = 0,cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt += a[i];
		b[i] = a[i] + b[i-1];
	}
	sort(a+1,a+n+1,cmp);
	if( n == 3 ){
		if(cnt > a[1]*2){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	return 0;
}
