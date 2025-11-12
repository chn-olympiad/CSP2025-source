#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int> mp;
int maxn;
string ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			mp[s[i]]++;
		}
	}
	for(char i='9';i>='0';i--){
		if(mp[i]!=0){
			for(int j=1;j<=mp[i];j++) ans+=i;
		}
	}
	cout<<ans;
    return 0;
}

