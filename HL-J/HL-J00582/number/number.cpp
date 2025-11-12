#include<bits/stdc++.h>
using namespace std ;
char a[1000005] ;
long long c = 0 ;
int cmp(int x,int y){
	return x > y ;
}
int main(){
	freopen("number.in","w",stdin) ;
	freopen("number.out","r",stdout) ;
	string s ;
	cin >> s ;
	long long n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i] = s[i] ;
			c++ ;
		}
	}
	sort(a,a+n,cmp) ;
	for(int i = 0;i < c;i++){
		cout << a[i] ;
	}
	return 0 ;
}
