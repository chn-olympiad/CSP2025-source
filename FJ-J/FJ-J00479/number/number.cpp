#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>a;
	int x=s.length();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int tmp=s[i]-'0';
			a.push_back(tmp);
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
