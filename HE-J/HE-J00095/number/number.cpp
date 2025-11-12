#include<iostream>
using namespace std;
string s;
int all[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			all[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(all[i]>0)
		{
			for(int k=1;k<=all[i];k++)
			{
				cout<<i;
			}
		}
	}
	return 0;
 } 
 /*#Shang4Shan3Ruo6Shui4*/	
