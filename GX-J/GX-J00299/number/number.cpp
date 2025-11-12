#include<bits/stdc++.h>
using namespace std;
char a[1000005];
string s;
int n,x=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a[x]=s[i];
            x++;
        }
    }
    sort(a,a+x,cmp);
    for(int i=0;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
