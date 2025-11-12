#include<bits/stdc++.h>
using namespace std;
string s;
int t[12];	
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s; 
    int len=s.length();
    for(int i=0;i<len;i++)
        if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	bool flag=false;
    for(int i=1;i<=9;i++)
        if(t[i]>=1) flag=true;
    if(!flag&&t[0]>=1)
    {
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--)
        if(t[i]>=1)
            for(int j=1;j<=t[i];j++) cout<<i;
    return 0;
}
