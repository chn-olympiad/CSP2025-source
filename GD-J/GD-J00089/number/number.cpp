#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>

using namespace std ;

string s ;
vector<int> res ;

int main()
{
	freopen("number.in", "r", stdin) ;
	freopen("number.out", "w", stdout) ;
	
	cin >> s ;
	for (int i = 0, Len = s.size() ; i < Len ; i ++ )
		if (s[i] >= '0' && s[i] <= '9')
			res.push_back(s[i] - '0') ;
	
	sort(res.begin(), res.end()) ;
	reverse(res.begin(), res.end()) ;
	
	for (int i = 0, Len = res.size() ; i < Len ; i ++ )
		cout << res[i] ;
	cout << '\n' ;
	
	return 0 ;
}
