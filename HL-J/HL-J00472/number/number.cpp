#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
    freoprn("number.in","r",stdin);
    freoprn("number.out","r",stdout);
    string x;
    long long ans=1,b=1,d=1;
    long long s=0;
    cin>>x;
    for (int i=0;i<x.size();i++)
    {

        if ('0'<=x[i] && x[i]<='9')
        {

            a[ans]=x[i]-48;
            ans++;
        }
    }

    sort(a+1,a+ans);
    for (int i=1;i<ans;i++)
    {
        if (a[i]==0)
        {
            d*=10;
        }
        s+=a[i]*b;
        b*=10;
    }
    cout<<s;
}
