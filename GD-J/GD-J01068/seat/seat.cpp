#include<bits/stdc++.h>
using namespace std;
long long n, m, a[105],idx, fs, ansh, ansl;
bool cmp(long long a, long long b){
	return a > b;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	long long len = n*m;
	for(long long i = 1; i <= len; i++){
		cin >> a[i];
	} 
	fs = a[1];
	sort(a+1,a+1+len,cmp);
	for(long long i = 1; i <= len; i++){
		if(a[i]==fs)idx=i;
	}
	long long tmp = idx/n;
	long long l = (idx%n!=0 ? tmp+1 : tmp);
//	cout << idx << endl << idx%n-1 << endl;
	if(n%2==1){
		if(l%2==1){
			ansl = l;
			ansh = (idx%n!=0 ? idx%n : m);
		}else{
			ansl = l;
			ansh = (idx%n!=0 ? m-(idx%n) : 1);
		}
	}else{
//		cout << 1 << endl;
		if(l%2==1){
			ansl = l;
			ansh = (idx%n!=0 ? idx%n : m);
		}else{
//			cout << 1 << endl;
			ansl = l;
			ansh = (idx%n!=0 ? m-(idx%n-1) : 1);
		}
	}
	
	cout << ansl << ' ' << ansh << endl;
	return 0;
}
