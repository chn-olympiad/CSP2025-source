#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,num[N];
string str;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();++i)
		if(str[i]<='9'&&str[i]>='0')
			num[str[i]-'0']++;
	for(int i=9;i>=0;--i)
	{
		if(num[i]==0)
			continue;
		else
		{
			for(int j=1;j<=num[i];j++)
				cout<<i;
		}	
	}		
	return 0;
}
