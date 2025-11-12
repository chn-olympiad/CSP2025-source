#include <bits/stdc++.h>
using namespace std;

const int N=1e6+1;
string s;
int num[N],j;

int main()
{
	freopen("number.in","cin",stdin);
	freopen("number.out","cin",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int data;
		char c=s[i];
		if(c<='9'&&c>='0')
		{
			data=c-'0';
			num[++j]=data;
		}
	}
	sort(num+1,num+j+1);
	while(j--)cout<<num[j+1];
	return 0;
}