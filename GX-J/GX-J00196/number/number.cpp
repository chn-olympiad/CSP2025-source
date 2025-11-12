#include <bits/stdc++.h>
using namespace std;
char a[100005];
int b[100005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i=0,j=0,m=0;
    cin>>a;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            b[j]=a[i]-48;
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        m=i;
        for(int k=i+1;k<j;k++)
        {
            if(b[k]>b[m]) m=k;
        }
        swap(b[m],b[i]);
        cout<<b[i];
    }

    return 0;
}
