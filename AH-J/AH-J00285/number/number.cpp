#include <bits/stdc++.h>
using namespace std;
string s,sum;
int n;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
n=s.size();
if(n==1)
{
	if(s[0]>='0' and s[0]<='9')
	return cout<<s,0;
	}
for(int i=0;i<n;i++)
	 if(s[i]=='9')sum+=s[i];
	 for(int i=0;i<n;i++)
	  if(s[i]=='8')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='7')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='6')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='5')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='4')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='3')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='2')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='1')sum+=s[i];
	 for(int i=0;i<n;i++)
	 if(s[i]=='0')sum+=s[i];
cout<<sum;
return 0;
}
