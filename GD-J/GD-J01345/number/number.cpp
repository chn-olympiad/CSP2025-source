#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			a[++c]=s[i]-48;
	sort(a+1,a+1+c);
	for(int i=c;i>=1;i--)
		cout<<a[i];	
	return 0;
} 
