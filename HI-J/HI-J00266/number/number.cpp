#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	int a[n];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-48<=0&& (s[i])-48<=9)
		{
			a[n]=s[i];
			a[nfclose(stdin);]++;
		}
	}
	sort(a,a+n);
	for(int i=n;i>=0;i--)
	{
		cout<<a[n]-48;
	}
	cout<<a[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

