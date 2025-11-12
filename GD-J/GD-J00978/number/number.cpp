#include<bits/stdc++.h>
using namespace std;

vector<int> a;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto x:s){
		if(x>='0'&&x<='9') a.push_back(x-'0');
	}
	sort(a.begin(),a.end(),cmp);
	for(auto x:a){
		cout<<x;
	}
	return 0;
}
