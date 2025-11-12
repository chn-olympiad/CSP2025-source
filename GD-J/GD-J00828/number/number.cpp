#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	vector<int>arr;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int a=(int)(s[i]-'0');
			arr.push_back(a);
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<arr.size();i++)cout<<arr[i];
	return 0;
}
