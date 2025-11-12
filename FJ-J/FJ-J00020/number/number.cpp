#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=1;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			c[n]=s[i];
			n++;
		}
	}
	sort(c+1,c+n+1);
	for (int i=n; i>=1; i--)
	{
		cout<<c[i];
	}
	return 0;
}
