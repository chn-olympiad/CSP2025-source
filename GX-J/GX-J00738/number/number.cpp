#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
		s[i]-='0';
		if(s[i]<='9') s1[i]=s[i];
	}
	for(int i=0;i<s1.size()-1;i++)
	{
		for(int j=i+1;j<s1.size();j++)
		{
			if(s1[i]<s1[j]) swap(s1[i],s1[j]);
		}
	}
	for(int i=0;i<s1.size();i++)
	{
		cout<<(int)s1[i];
	}
    return 0;
}
