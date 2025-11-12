#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int num=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	if(len<=1) cout<<s;
	else if(len>1&&len<=2)
	{
		for(int i=0; i<len; i++)
		{
			if(s[i]!='a')
			{
				cout<<s;
				
			}
			else 
			{
				num=s[len]-'a';
				cout<<num;
			}
		}
	} 
	else
	{
		cout<<len*len;
	}	
	return 0;
}
