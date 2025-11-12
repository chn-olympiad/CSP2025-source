#include<bits/stdc++.h>
using namespace std;
vector<int>num;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto u:s){
		if('0'<=u&&u<='9'){
			num.push_back(u-'0');
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(auto u:num)cout<<u;
	return 0;
}
