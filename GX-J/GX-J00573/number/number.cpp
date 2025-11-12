#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> g;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9) g.push_back(s[i]-'0');
	}
	sort(g.begin(),g.end());
	int m=g.size();
	for(int i=m-1;i>=0;i--) cout<<g[i];
	return 0;
}
