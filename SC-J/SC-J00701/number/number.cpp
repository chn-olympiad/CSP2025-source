#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a+=s[i]-'0';
		}
	}
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	} 
	for(int i=0;i<a.size();i++)
	{
		cout<<int(a[i]);
	}
	return 0;
}