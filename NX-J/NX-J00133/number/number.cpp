#include<bits/stdc++.h>
using namespace std;
long long b[1000010]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int x=1;
    for(long long i=0;i<a.size();i++)
    {
        if(isdigit(a[i])==true)
        {
            b[x]=a[i]-'0';
            x++;
        }
    }
    x-=1;
    for(long long i=1;i<=x;i++)
    {
        for(long long j=i;j<=x;j++)
        {
            if(b[i]<b[j])
            {
                swap(b[i],b[j]);
            }
        }
    }
    for(int i=1;i<=x;i++)
    {
        cout<<b[i];
    }
    return 0;
}
