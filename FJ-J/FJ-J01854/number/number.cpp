#include<bits/stdc++.h>
using namespace std;
int a[1000005],k=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--)
	cout<<a[i];
	return 0;
}
