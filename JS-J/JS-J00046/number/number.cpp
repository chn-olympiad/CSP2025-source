#include<bits/stdc++.h>
using namespace std;
int a[14];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    cin>>x;
    for(int i=0;i<=x.length();i++)
    {
        for(int j=48;j<=57;j++)
           if(x[i]==j)
                a[j-48]++;
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i])
        {
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
