#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			a[++ans]=s[i]-48;
//	for(int i=1;i<=ans;i++)
//		cout<<a[i]<<" ";
	sort(a+1,a+1+ans);
	for(int i=ans;i>=1;i--)
		cout<<a[i];
	return 0;
 } 
