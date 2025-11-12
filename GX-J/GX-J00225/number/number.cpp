#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    char a[1000000];
    int i,j=0,b[1009],c[1009],d=-1,k,l=0,m,n;
    cin>>a;
    for(i=0;i<strlen(a);++i)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            b[j]=a[i]-'0';
            j++;
        }
    }
    for(i=0;i<j;++i)
    {
        for(k=0;k<j;++k)
        {
            if(b[k]>d)
            {
                d=b[k];
            }
        }
        c[l]=d;
        l++;
        for(m=0;m<j;++m)
        {
            if(b[m]==d)
            {
                b[m]=-1;
                d=-1;
            }
        }
    }
    for(i=0;i<j;++i)
    {
        cout<<c[i];
    }
    return 0;
}
