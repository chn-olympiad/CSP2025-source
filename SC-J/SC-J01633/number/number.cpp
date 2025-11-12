#include<bits/stdc++.h>
using namespace std;
char s[1000002];
int i,ans[1000002],j=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<strlen(s);i++)
	    if(s[i]=='1'||s[i]=='2'||s[i]=='0'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
	    {
	    	ans[j]=s[i]-48;
	    	j++;
		}
    sort(ans+1,ans+j+1);
    for(i=j;i>1;i--)
        cout<<ans[i];
	return 0;
}