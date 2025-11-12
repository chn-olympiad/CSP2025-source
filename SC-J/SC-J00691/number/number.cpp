#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length();
	vector<int> b,c;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			c.push_back(s[i]-'0');
		}
	}
	int sc=c.size();
	sort(c.begin(),c.end());
	for(int i=sc-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}