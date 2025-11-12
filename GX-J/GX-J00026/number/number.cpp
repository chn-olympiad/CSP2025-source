#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000005]={0};
    int b[1000005]={0};
    cin>>a;
    int j=0;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[j]=a[i]-'0';
            j++;
        }
    }
    for(int i=0;i<j;i++)
    {
        for(int k=j-1;k>=i+1;k--)
        {
            if(b[k]<b[k-1])swap(b[k],b[k-1]);
        }
    }
    for(int i=0;i<j;i++)cout<<b[i];
    return 0;
}
