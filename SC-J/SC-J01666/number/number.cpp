#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long c=1;
int main(){
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[c]=s[i]-48;
			c++;
		}
	}
	sort(a+1,a+c); 
	for(int i=c-1;i>=1;i--)
	{
		cout<<a[i];
	} 
	return 0;
 } 