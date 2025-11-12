#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]);
	}
	stable_sort(v.begin(),v.end(),cmp);
	for(auto x:v) cout<<x;
	return 0;
}
