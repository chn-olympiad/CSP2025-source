#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char c : s){
		if(c <= '9' && c >='0'){
			a.push_back(c - '0');
		}
	}
	sort(a.begin(),a.end());
	for(int i= a.size()-1 ; i> -1;i--){
		printf("%d",a[i]);
	}
	return 0;
	//Çó¹ý 
}
