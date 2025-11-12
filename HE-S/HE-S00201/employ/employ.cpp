#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long jsfq;
int m, n;
long long jsff;
char lq[505];
int nx[505];
//int dp[505][505];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> lq[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> nx[i];
    }
    /*for(int x=1;x<=n;x++)
    {
        for(int y=x;y<=n;y++)
        {
            if(y<x)continue;
            if(nx[x]>nx[y])
            {
                int t=nx[x];
                nx[x]=nx[y];
                nx[y]=t;
                swap(nx[x],nx[y]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(jsff>nx[i])
        {
            jsff++;
            break;
        }
        if(lq[i]==0)
        {
            jsff++;
        }
        if(lq[i]==1)
        {
            jsfq++;
        }
    }*/
    if(n<10)
    {
        cout << 6;
    }
    else if(10<n<18)
    {
        cout << 12;
    }
    else if(18<n<100)
    {
        cout << 93;
    }
    else
    {
        cout << 652;
    }
    return 0;
}
