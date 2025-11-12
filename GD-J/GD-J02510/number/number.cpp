#include<bits/stdc++.h>
#include<string>
using  namespace std;
int main()
{
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	string s;
	int n=0;
	int a[100005];
	cin>>s;
	int i=0;
	i=s.size;
	while(i)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		a[i]=s[i];
		n++;
		i--;
	}
	sort(a[0],a[n-1]);
	for(int j=n-1;j>=0;j--)
	{
		cout<<a[j];
	}
}
