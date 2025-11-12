#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>arr;
string S;int n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin >> S;n = S.length();
	for(char c : S){
		if('0' <= c && c <= '9') arr.emplace_back(c);
	}sort(arr.begin(),arr.end(),[&](int a,int b){return a > b;});
	for(char c : arr) cout << c;
	cout << "\n";
	return 0;
}