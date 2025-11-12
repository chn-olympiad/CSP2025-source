#include<bits/stdc++.h>
using namespace std;

long long n, a[1001], l, r, k, a_0[1001];

string bl(int x){
	string miku;
	int a = x, b;
	while (a-1){
		b = x%2;
		a /= 2;
	    miku = char(b+48) + miku;
	}
	return miku;
}

string XOR(int x, int y){
	string num="", a=bl(x), b=bl(y);
	for(int i=0; i<=max(a.size(), b.size()); i++){
	    if (a[i]=='1'||b[i]=='1')  num += "1";
	    else num += "0";
	}
	return num;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for (; l<=n; l++){
		for(r=l; r<=n; r++){
			
		}
	} 
	return 0;
}

