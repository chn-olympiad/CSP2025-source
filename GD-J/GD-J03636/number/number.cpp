#include<iostream>
using namespace std;
long long a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i])
		{
			printf("%d",i);
			a[i]--;
		}
	}
    return 0;
}
