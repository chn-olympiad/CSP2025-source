#include <bits/stdc++.h>  
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >>s;
	vector<char> a;
	for(int ch :s){
		if(ch>='0' && ch<='9') a.push_back(ch);
	}
	sort(a.rbegin(),a.rend());
	for(char i : a) cout <<i;
	return 0;
}
