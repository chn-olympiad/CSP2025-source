#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000001];
	cin>>s;
	int j=0,n=s.size();
	for(int i=0;i<=n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			a[j]=s[i];
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
