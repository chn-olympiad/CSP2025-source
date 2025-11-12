#include <iostream>
#include <cstring>
using namespace std;
#define endl '\n'
int n,q,len,posl,posr;
string s[200001][2],str1,str2,str0,str;
bool flag;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		cin>>str1>>str2;
		if(str1.size()!=str2.size())
		{
			cout<<0<<endl;
			continue;
		}
		len=str1.size();
		for(int i=0;i<len;i++)
		{
			if(str1[i]!=str2[i])
			{
				posl=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--)
		{
			if(str1[i]!=str2[i])
			{
				posr=i;
				break;
			}
		}
		str0=str1.substr(posl,posr-posl+1);
		str=str2.substr(posl,posr-posl+1);
		flag=false;
		for(int i=1;i<=n;i++)
		{
			if(s[i][0]==str0&&s[i][1]==str)
			{
				flag=true;
				break;
			}
		}
		if(!flag)
		{
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}

