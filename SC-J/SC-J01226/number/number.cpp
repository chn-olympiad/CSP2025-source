#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool b=0;string s;int a[10]={0};cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=1;i<=9;i++)if(a[i]){
		b=1;break;
	}
	if(b)for(int i=9;i>=0;i--)for(int j=0;j<a[i];j++)cout<<i;
	else cout<<0;
	return 0;
}