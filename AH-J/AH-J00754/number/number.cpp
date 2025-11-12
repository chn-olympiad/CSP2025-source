#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	cin>>s;
	int k=s.size();
	for (int i=0;i<k;i++)
	    if (s[i]>='0'&&s[i]<='9')
	        s1+=s[i];
	int k2=s1.size();
	for (int i=0;i<k2;i++)
	    for (int j=i+1;j<k2;j++)
	        if (s1[i]-'0'<s1[j]-'0')
	            swap(s1[i],s1[j]);
	cout<<s1;
	return 0;
}
