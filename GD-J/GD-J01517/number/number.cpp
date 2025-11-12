#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001000],ans,t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>=48&&s[i]<=57)
		{
			a[t]=int(s[i]-48);
			t++;
			ans++;
		}	
	sort(a,a+ans);
	for(int i=ans-1;i>=0;i--)
		cout<<a[i];
	return 0;
} 
