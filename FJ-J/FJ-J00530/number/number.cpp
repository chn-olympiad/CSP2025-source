#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	vector<int> v;
	for(char i:s){
		if(i>='0'&&i<='9'){
			v.push_back(i-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0]==0)cout<<0;
	else{
		for(int i:v){
			cout<<i;
		}
	}
}

