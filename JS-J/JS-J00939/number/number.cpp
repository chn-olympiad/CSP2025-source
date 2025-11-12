#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int m=0;
    int a[n];
    for(int i=0;i<s.size();i++)
    {
        if(s[i]-48>=0 && s[i]-48<=9)
        {
            a[m]=s[i]-48;
            m++;
        }
    }
    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<a[i];
    }
    return 0;
}
