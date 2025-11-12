#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
string ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int c;
			c=s[i]-'0';
			a[c]++; 
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			char c;
			c=i+'0';
			ans=ans+c; 
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
} 