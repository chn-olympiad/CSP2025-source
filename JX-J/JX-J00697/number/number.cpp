#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long b=0,c=1;
    char a[1000001];
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[c]=s[i];
            b++;
                c++;
        }
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b-1;j++)
        {
            int x;
            if(a[j]<a[j+1])
            {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    for(int i=1;i<=b;i++)
    {

        cout<<a[i];
    }
    return 0;
}
