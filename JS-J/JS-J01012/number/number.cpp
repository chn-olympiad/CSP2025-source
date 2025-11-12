#include <iostream>
#include <algorithm>
using namespace std;

string s;
char digits[1000005];
int digitCnt;

bool cmp( char x, char y ){ return x > y; }

int main(){
	freopen( "number.in", "r", stdin );
	freopen( "number.out", "w", stdout );
	cin >> s;
	for ( int i = 0; i < s.size(); i++ )
		if ( s[i] >= '0' && s[i] <= '9' )
		{
			digits[ digitCnt ] = s[i];
			++digitCnt;
		}
	sort( digits, digits+digitCnt, cmp );
	for (int i=0; i < digitCnt; i++)
		cout << digits[i];
	cout << endl;
	return 0;
}