#include<bits/stdc++.h>
using namespace std;
string s,y;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			y=y+s[i];
		}
	}
	sort(y.begin(),y.end());
	reverse(y.begin(),y.end());
	cout<<y;
	return 0;
}
