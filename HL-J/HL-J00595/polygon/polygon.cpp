#include<bits/stdc++.h>
using namespace std;
int n,a[10000],K,s;
void f(int i,int k){
	if(i <= n-K+1) f(i+1,k);
	int h = 0;
	for(int j = i-K+1;j >= 1;j--) h+=a[j];
	if(h > a[i]){
		s += 1;
	}
	if (k != 0){
	f(i,k-1);
	}
}
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 3;i <= n;i++){
		K = i;
		f(1,i);
	}
	cout << (s % 998244353)/n ;
	return 0;
}
