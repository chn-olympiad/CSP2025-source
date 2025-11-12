#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char a[100000],max0;
    int i=0,j=0,o,k;
    cin>>s;
    while(s[i]!='\0')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j]=s[i];
            j++;
        }
        i++;
    }   
    for(k=0;k<j;k++)
    {
        max0=-1;
        for(i=0;i<j;i++)
    {
        if(max0<a[i]&&a[i]!='a')
        {
            max0=a[i];
            o=i;
        }
    }
    a[o]='a'; 
    cout<<max0;
    }
    return 0;
}