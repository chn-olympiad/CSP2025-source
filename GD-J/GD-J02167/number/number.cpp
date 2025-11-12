#include<bits/stdc++.h>
using namespace std;
string s;
long long a[9999999],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')a[++b]=int(s[i]-'0');
	}
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--)cout<<a[i];
	return 0;
} 
