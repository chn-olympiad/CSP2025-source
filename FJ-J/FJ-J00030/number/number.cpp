#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int a[1000005];
char t[100005];
int n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int j=n;j>=2;j--)
	{
		cout<<a[j];
	} 
	return 0;
} 
