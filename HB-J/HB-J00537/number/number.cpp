#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[1000];
    int b,c=0;
    cin>>s;
    b=long(s);
    int a[b];

    for(int i=0;i<b;++i)
    {
        if(s[i]>=char(1)&&s[i]<=char(9))
            a[i]=int(s[i]);
    }
    for(int i=0;i<b;++i)
    {
        if(a[i]<a[i+1])
        {
            c=a[i];
            a[i]=a[i+1];
            a[i+1]=c;
        }
    }
    for(int i=0;i<b;++i)
    {
        cout<<a[i];
    }


    return 0;
}
