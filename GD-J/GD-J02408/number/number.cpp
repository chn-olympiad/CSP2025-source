#include<bits/stdc++.h>
//rp++
//ccf let me passed
//48181542
//Eason2010 
using namespace std;
string s,a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(auto c : s){
		if('0' <= c and c <= '9')
		a += c;
	}
	sort(a.begin(),a.end(),greater<char>());
	cout << a;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
