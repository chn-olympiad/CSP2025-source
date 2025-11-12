#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.length();
	for(int i=0;i<n;i++)
		if('0'<=s[i]&&s[i]<='9') v.push_back(s[i]-'0');
	sort(v.begin(),v.end());
	if(v[v.size()-1]==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=v.size()-1;i>=0;i--) cout<<v[i];
	return 0;
}
