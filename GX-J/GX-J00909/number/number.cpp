#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    int a[n+10];
    memset(a,0,sizeof(a));
    for(int i=0;i<=n;i++)
    {
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			a[i]=s[i]-'0'+1;
		}
	}
	sort(a,a+n+1,cmp);
	for(int i=0;i<=n;i++)
	{
		if(a[i]!=0)cout<<a[i]-1;
	}
    return 0;
}
