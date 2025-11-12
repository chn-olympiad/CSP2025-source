#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ss[s.length()+1],l=0,ll=s.length();
	for(int i=0;i<=ll;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			l++;
			ss[l]=s[i]-'0';
		}
	}
	sort(ss+1,ss+1+l);
	for(int i=l;i>0;i--)
		cout<<ss[i];
	return 0;
}
