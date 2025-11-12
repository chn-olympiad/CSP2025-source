#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>dgt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)if(isdigit(s[i]))dgt.push_back(s[i]-'0');
	sort(dgt.begin(),dgt.end(),greater<int>());
	for(int i=0;i<dgt.size();i++)cout<<dgt[i];
	return 0;
}

