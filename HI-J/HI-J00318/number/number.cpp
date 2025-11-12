#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool f(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string s;
	int n=1;
	cin>>s;
	int l=s.size()-1;
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
