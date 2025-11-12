#include<bits/stdc++.h>
using namespace std;

string s;
vector<int>v; 
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i) if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),greater<int>());
	for(int i:v) cout<<i;
	return 0;
}
