#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	vector<int>arr;
	string s;
	cin>>s;
	for(char c:s){
		if (c>='0'&&c<='9'){
			arr.push_back(c-'0');
		}
	}
	sort(arr.begin(),arr.end(),greater<int>());
	for(int i : arr){
		cout<<i;
	}
	
	return 0;
}