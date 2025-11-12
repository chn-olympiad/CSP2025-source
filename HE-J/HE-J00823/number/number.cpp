#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')ss+=s[i];
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	cout<<ss<<endl;
	return 0;
}
