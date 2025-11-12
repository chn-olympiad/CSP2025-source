#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n[10] = {0,0,0,0,0,0,0,0,0,0};
	string a ;
	cin>>a;
	long long t = a.size();
	for(long long i = 0 ; i < t ; i++ ){
		if(a[i]>='0' && a[i]<='9'){
			n[a[i]-'0']++;
		}
		
	}
	string cnt = "" ;
	for(int k = 9 ; k >= 0 ; k--){
		for(long long j = 0 ; j < n[k] ; j++){
			cnt = cnt + char(k+'0') ;
		}
	}
	cout << cnt ;
	return 0;
}

