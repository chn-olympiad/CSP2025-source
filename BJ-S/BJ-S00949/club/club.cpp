#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,maxn=0,total=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a1>>a2>>a3;
            maxn=max(max(a1,a3),max(a1,a2));
            total=total+maxn;
        }
        printf("%d",total);
    }
}
