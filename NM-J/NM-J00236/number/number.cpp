#include<bits/stdc++.h>
using namespace std;
string s,a,b;
long long m,n,i,c,r,maxa,x;
char j;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length();
	for(i=0;i<len;i++)
	{
		if(s[i]<'0'||s[i]>'9') continue;
		for(j='0';j<='9';j++)
		{
			if(s[i]>=j&&s[i]<='9')
			{
				a[i]+=s[i];
				break;
			}
		}
		cout<<a[i];
	}
	return 0;
}
