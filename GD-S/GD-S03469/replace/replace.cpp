#include <bits/stdc++.h>
using namespace std;
const int nn = 2e5 + 5;
int n , q;
string s[nn] , s1[nn];
int main (){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 0;i < n;i ++){
		cin >> s[i] >> s1[i];
	} 
	int sum = 0;
	for(int i = 0;i < q;i ++){
		string t1 , t2;
		cin >> t1 >> t2;
		for(int i = 0;i < t1.size();i ++){
			string x , y , z;
			for(int j = 0;j < t1.size();j ++){
				for(int k = 0;k < t1.size();k ++){
					string a = t1.substr(0 , i);
					string b = t1.substr(i + 1 , j);
					string c = t1.substr(j + 1 , k);
					cout << a << " " << b << " " << c << endl;
					for(int i = 0;i < n;i ++){
						if(b == s[i]){
							b = s1[i];
							break;
						}
					}
					string u = a + b + c;
					if(u == t2) sum ++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
