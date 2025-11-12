#include<bits\stdc++.h>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//0 48 9 57
	string s;
	
	getline(cin,s);
	
	vector<int> arr;
	for (char c: s)
		if ((int)c>=48&&(int)c<=57) arr.push_back(c-'0');
	sort(arr.begin(),arr.end(),cmp);
	
	for (int c: arr)
		cout << c;
	return 0;
}