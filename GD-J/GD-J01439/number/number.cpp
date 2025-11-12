#include <bits/stdc++.h>

using namespace std;

string s;
stringstream ss;
int cnt = 0;
long long a[1000002];

int main(){
	
	ifstream fin("number.in");
	ofstream fout("number.out");
	fin >> s;
	int len = s.length();
	for( int i = 0; i <= len - 1; ++ i ){
		if( s[ i ] >= '0' && s[ i ] <= '9' ){
			++ cnt;
			a[ cnt ] = s[ i ] - '0';
		}
	}
	sort( a, a + cnt + 1 );
	if( a[ cnt ] == 0 ){
		fout << 0;
	}else{
		for( int i = cnt; i >= 1; -- i ){
			fout << a[ i ];
		}	
	}
	fin.close();
	fout.close();
	
	return 0;
	
} 
