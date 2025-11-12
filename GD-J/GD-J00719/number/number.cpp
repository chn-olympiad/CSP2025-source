#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	vector<int> c;
	for(char i:s){
		if(isdigit(i)) c.push_back(i-'0');
	}
	sort(c.begin(),c.end(),cmp);
	for(int i:c) cout << i;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
