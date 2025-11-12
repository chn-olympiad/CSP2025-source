#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto c : s)
		if(isdigit(c)) a.push_back(c-'0');
	sort(a.begin(),a.end());
	if(a.back()==0) cout<<0;
	else 
		for(int i=a.size()-1;i>=0;i--) cout<<a[i];
	return 0; 
}
