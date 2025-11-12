#include <bits/stdc++.h>
using namespace std;
int h[1000005];
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			h[i]=s[i]-48;
		}
		else
		{
			h[i]=-1;
		}
    }
	sort(h+0,h+s.size(),cmp);
	for(int i=0;i<=s.size()-1;i++)
	{
		if(h[i]!=-1)cout<<h[i];
		else break;
	}
	return 0;
 } 
