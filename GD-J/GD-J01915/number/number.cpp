#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) c[i+1]=s[i];
	sort(c+1,c+1+s.size());
	for(int i=s.size();i>=1;i--) if(c[i]>='0'&&c[i]<='9') cout<<c[i];
}
