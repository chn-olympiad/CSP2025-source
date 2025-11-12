#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[1000],x[1000];
int a[15000];
long long cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    int e=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        e=max(a[i],e);
        sum2+=a[i];
    }
    if(n==3)
    {
        if(sum2>e*2)
        {
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    int cnt=0;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n-i+2;j++)
        {
            int maxn=0,s=0;
            for(int k=j;k<=j+i-1;k++)
            {
                maxn=max(maxn,a[k]);
                s+=a[k];
                cout<<a[k]<<" "<<maxn<<" ";
            }
            cout<<endl;
            if(s>maxn*2)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
