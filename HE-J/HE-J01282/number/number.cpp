#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s,s1;
bool cmp(char x,char y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	sort(s1.begin(),s1.end(),cmp);
	if(s1[0]=='0'){
		cout<<"0\n";
		return 0;
	}
	else{
		for(int i=0;i<s1.size();i++)
		{
			cout<<s1[i];
		}
	}
	return 0;
}
