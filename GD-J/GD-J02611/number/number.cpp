#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	vector<int>vec;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto v:s){
		if(v>='0'&&v<='9'){
			vec.push_back(v-'0');
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	for(auto v:vec){
		cout<<v;
	}
	puts("");
	return 0;
}
