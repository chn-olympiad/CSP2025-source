#include<bits/stdc++.h>
using namespace std;

string a;
long long cnt=1,x,n[1000000+5];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>a;

    int i=0;
    while(a[i])
    {
        if(a[i]=='0')
        {
            n[cnt]=0;
            cnt++;
        }
        else if(a[i]=='1')
        {
            n[cnt]=1;
            cnt++;
        }
        else if(a[i]=='2')
        {
            n[cnt]=2;
            cnt++;
        }
        else if(a[i]=='3')
        {
            n[cnt]=3;
            cnt++;
        }
        else if(a[i]=='4')
        {
            n[cnt]=4;
            cnt++;
        }
        else if(a[i]=='5')
        {
            n[cnt]=5;
            cnt++;
        }
        else if(a[i]=='6')
        {
            n[cnt]=6;
            cnt++;
        }
        else if(a[i]=='7')
        {
            n[cnt]=7;
            cnt++;
        }
        else if(a[i]=='8')
        {
            n[cnt]=8;
            cnt++;
        }
        else if(a[i]=='9')
        {
            n[cnt]=9;
            cnt++;
        }
        i++;
    }

    sort(n,n+cnt);

    for(int i=cnt-1;i>=1;--i)
    {
        for(int k=1;k<i;++k)
            n[i]*=10;
        x+=n[i];
    }

    cout<<x;

    return 0;
}
