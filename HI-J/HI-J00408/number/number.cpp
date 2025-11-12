#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int max=0;
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		a[i]=s[i];
		if(a[i]>max)
		{
			cout<<a[i];
			continue;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
