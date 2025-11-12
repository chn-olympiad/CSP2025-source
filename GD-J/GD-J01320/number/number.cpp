#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') num.push_back(s[i]-'0');
	} 
	sort(num.begin(),num.end(),cmp);
	for(auto i:num) cout<<i;
	return 0;
} 
