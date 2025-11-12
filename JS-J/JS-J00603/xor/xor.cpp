#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,ct0,ct1;
bool a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ct0+=!a[i],ct1+=a[i];
    }
    if(!k)
    {
        ct1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]&&a[i+1])
            {
                ct1++,i++;
            }
        }
        cout<<ct0+ct1;
    }
    else
    {
        cout<<ct1;
    }
    return 0;
}
