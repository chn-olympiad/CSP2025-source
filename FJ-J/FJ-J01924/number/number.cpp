#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char ch;
vector<char> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(cin>>ch){
		if('0'<=ch&&ch<='9')v.push_back(ch);
	}
	sort(v.begin(),v.end(),greater<char>());
	for(auto i:v)cout<<i;
}
