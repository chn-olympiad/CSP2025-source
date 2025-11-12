#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	vector<int>arr;
	for(char c:s){
		if('0'<=c&&c<='9')arr.push_back(c-'0');
	}
	sort(arr.begin(),arr.end());
	reverse(arr.begin(),arr.end());
	for(int i:arr)cout<<i;
	return 0;
}