#include<bits\stdc++.h>
using namespace std;
string s;int c[1000005],l=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]>=48&&s[i]<=57)
		{
			c[l]=s[i]-'0';
			l++;
		}  
	}
	sort(c,c+l);
	for(int i=l-1;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	return 0;
} 