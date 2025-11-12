#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int i,j=0,k,m,n,a[1000000];
    for(i=1;i<=s.size();i++)
    {
        if('0'<=s[i] && s[i]<='9')
        {
            a[j]=s[i];
            j++;
        }
    }
    for(k=0;k<=j;k++)
    {
        for(m=k+1;m<=j;m++)
        {
            if(a[k]<a[m])
            {
                char ch=a[k];
                a[k]=a[m];
                a[m]=ch;
            }
        }
    }
    for(n=0;n<=j;n++) cout<<a[n];
    return 0;
}
