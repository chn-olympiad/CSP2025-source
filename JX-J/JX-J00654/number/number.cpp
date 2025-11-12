#include<bits/stdc++.h>
using namespace std;
string s;
int n,m=-1,a[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.length();
    for (int i=0;i<n;i++)
    {
        if (s[i]>='0' &&  s[i]<='9')
        {
            int b=s[i]-'0';
            a[b]++;
            m=max(m,b);
        }
    }
    for (int i=m;i>=0;i--)
    {
        while (a[i]>0)
        {
            cout<<i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
