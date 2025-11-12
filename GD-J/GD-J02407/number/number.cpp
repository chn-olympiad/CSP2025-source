#include <bits/stdc++.h>
using namespace std;

string s;
long long len,a,s2[1000005];

bool cmp(long long x,long long y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a++;
			s2[a]=s[i]-'0';
		}
	}
	sort(s2+1,s2+a+1,cmp);
	for(int i=1;i<=a;i++)
	{
		cout<<s2[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
