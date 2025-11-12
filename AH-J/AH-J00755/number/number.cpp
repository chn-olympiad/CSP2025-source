#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000000],c,n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]<='9' && s[i]>='0')
			a[++c]=s[i]-'0';
	sort(a+1,a+c+1);
	for(int i=c;i>=1;i--)
		cout<<a[i];
		
	return 0;
}	
