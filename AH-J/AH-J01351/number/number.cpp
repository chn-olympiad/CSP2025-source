#include<bits/stdc++.h>
using namespace std;
int s[100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s[a[i]]++;
        }
    }
    for(int i=57;i>=48;i--)
    {
        if(s[i]>0)
        {
            for(int j=1;j<=s[i];j++)
            {
                cout<<char(i);
            }
        }
    }
    return 0;
}
