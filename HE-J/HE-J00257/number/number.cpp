#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s,s1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') s1+=s[i];
	}
	sort(s1.begin(),s1.end());
	for(int i=s1.size()-1;i>=0;i--) cout<<s1[i];
	return 0;
}
