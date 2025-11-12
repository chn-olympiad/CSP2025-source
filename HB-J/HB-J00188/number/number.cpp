#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int c[1000010];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int b=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {

        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            b++;
            a[b]=s[i];
        }
    }

    for(int i=1;i<=b;i++)
    {

        c[i]=a[i]-'0';
    }
    sort(c+1,c+b+1);
    for(int i=b;i>=1;i--)
    {
        cout<<c[i];
    }
    return 0;
}
