#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int>a;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	} 
	sort(a.begin(),a.end(),greater<int>());
	for(auto t:a){
		cout<<a[t];
	}
	return 0;
}
