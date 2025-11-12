#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	string s;cin>>s;
	vector<int> arr;
	for(int i=0;i<s.length();i++){
		char p=s[i];
		if('0'<=p && p<='9'){
			arr.push_back(p-'0');
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
	}
	
}
	
