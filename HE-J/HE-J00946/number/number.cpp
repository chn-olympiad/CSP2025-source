#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000006],ss=0;
int tmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[ss++]=s[i]-'0';
		}
	}
	sort(ans,ans+ss,tmp);
	for(int i=0;i<ss;i++){
		cout<<ans[i];
	}
	return 0;
}
