#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;


int MOD=998244353;
int n=0,a[5005];
int b[5005];
int ans=0;
int cnt=0;


void suan(int y,int x)
{
    if(x==0)
    {
        int maxn=-1;
        for(int i=1;i<=cnt;i++)
            maxn=max(maxn,b[i]);
        if(y>maxn)ans++;
        ans=ans%MOD;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        bool d=true;
        for(int j=1;j<x;j++){
            if(a[i]==b[j])
            {
                d=false;
            }
        }
        if(d)
        {
            b[x]=a[i];
            suan(y+b[x],x-1);

        }
    }

}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        cnt=i;
        suan(0,i);
    }
    cout<<ans%MOD<<endl;
    return 0;
}

