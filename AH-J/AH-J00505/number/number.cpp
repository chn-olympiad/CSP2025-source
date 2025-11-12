#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out", "w",stdout);
    char s[1000001],a[1000001]={};
    int x=0,n;
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]<97||s[i]>123)
            {
                a[x]=s[i];
                x++;
            }
    }
     for(int i=0;i<strlen(a);i++)
     {
         for(int j=0;j<strlen(a);j++)
         {
             if(a[i]>a[j]&&i>j) swap(a[i],a[j]);
         }
     }
     cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
