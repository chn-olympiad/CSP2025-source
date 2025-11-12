#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int b[1000006],i=1,js,ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int m=a.size();
    while(m!=0)
    {
        m--;
        if(a[m]=='1')
        {
            b[js]=1;
            js++;
        }
        if(a[m]=='2')
        {
            b[js]=2;
            js++;
        }
        if(a[m]=='3')
        {
            b[js]=3;
            js++;
        }
        if(a[m]=='4')
        {
            b[js]=4;
            js++;
        }
        if(a[m]=='5')
        {
            b[js]=5;
            js++;
        }
        if(a[m]=='6')
        {
            b[js]=6;
            js++;
        }
        if(a[m]=='7')
        {
            b[js]=7;
            js++;
        }
        if(a[m]=='8')
        {
            b[js]=8;
            js++;
        }
        if(a[m]=='9')
        {
            b[js]=9;
            js++;
        }
        if(a[m]=='0')
        {
            b[js]=0;
            js++;
        }
    }
    sort(b,b+js+1);
    js++;
    for(int i=js;i>=0;i--)
    {
        if(i==6)
            ans+=b[i]*100000;
        if(i==5)
            ans+=b[i]*10000;
        if(i==4)
            ans+=b[i]*1000;
        if(i==3)
            ans+=b[i]*100;
        if(i==2)
            ans+=b[i]*10;
        if(i==1)
            ans+=b[i]*1;
        if(i==0)
            ans+=b[i]*0;
    }
    cout<<ans;
    return 0;
}
