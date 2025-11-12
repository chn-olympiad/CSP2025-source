#include<bits/stdc++.h>
using namespace std;
const int M=1e6+7;
int a[M];
string s;
long long q=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1)
		if(s[0]>='0' && s[0]<='9')
		{
			cout<<s;
			return 0;
		}
	for(int i=0;i<s.size();i++)
	{
			if(s[i]>='0' && s[i]<='9')
			{
				a[i]+=s[i]-'0';	
				q++;
			}
				
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=s.size()-q;i--)
	{
		if(i>=0)
			cout<<a[i];
		else
			break;
	}
    return 0;
}

