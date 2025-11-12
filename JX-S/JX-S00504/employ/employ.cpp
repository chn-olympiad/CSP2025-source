#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,c[510];
char s[510];
int main()
{
    freopen("employ.in","w",stdin);
    freopen("employ.out","r",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    int d=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==0)
            d=1;
    }
    int sum=0;
    if(d==0)
    {
        sum=1;
        for(int i=1;i<=n;i++)
        {
            sum*=i;
        }
        cout<<sum;
    }
}
