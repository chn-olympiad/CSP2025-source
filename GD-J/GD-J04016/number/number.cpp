#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);

	string s;
	cin >> s;
	
	long long cnt[10] = {0};
	for( long long i = 0 ; i < s.size() ; i++ ){
		if( s[i] <= '9' && s[i] >= '0' ){
			cnt[ s[i] - '0' ]++;
		}
	}

	for( int i = 9 ; i >= 0 ; i-- ){
		while( cnt[i]-- ){
			cout << i;
		}
	}
	return 0;
}
