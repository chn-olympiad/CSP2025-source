#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	vector<int> v;
	for(int i=0;i<n;i++) if(s[i]>='0' && s[i]<='9') v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),greater<int>());
	n=v.size();
	if(v[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++) cout<<v[i];
	return 0;
}
