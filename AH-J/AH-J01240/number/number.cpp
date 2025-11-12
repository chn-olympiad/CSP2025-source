#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()];
	int num=0;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[num]=int(s[i])-48;
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
