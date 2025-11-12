#include<bits/stdc++.h>
using namespace std;
string s;
using LL=long long;
LL a[10],x,ans;
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(LL i=0;i<s.size();i++)
    {
		if(s[i]<='9' && s[i]>='0')
		{
			x=int(s[i]-'0');
			a[x]++;
		}
	}
	for(LL i=9;i>=0;i--)
	    for(LL j=a[i];j>=1;j--)
	        cout<<i;           
    return 0;
}
