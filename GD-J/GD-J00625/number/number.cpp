#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],c = 0;
bool p( int x,int y ){
	return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for( char i : s ){
    	if( i >= '0' && i <= '9' ) a[c++] = i - '0';
	}
	sort(a,a + c,p);
	for( int i = 0;i < c;i++ ) cout << a[i];
    return 0;
}
