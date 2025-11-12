#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000055],num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]-'0'>=0 and s[i]-'0'<=9)
		{
			num++;
			n[num]=s[i]-'0';
		}
	}
	sort(n+1,n+num+1);
	for(int i=num;i>=1;i--)
		printf("%d",n[i]);
	return 0;
}

