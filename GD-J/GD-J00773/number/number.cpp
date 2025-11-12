#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0,len=s.size();i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a.push_back(s[i]);
		}
	}
	sort(a.begin(),a.end(),greater<char>());
	cout<<a;
	return 0;
}
