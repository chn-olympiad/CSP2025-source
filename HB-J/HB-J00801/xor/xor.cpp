#include<bits/stdc++.h>
using namespace std;
int n,k;
int s[1000],x[1000];
int a[1500000];
bool d=0;
long long cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]+=a[i]+s[i-1];
        if(a[i]!=0||a[i]!=1) d=1;
    }
    if(n<2)
    {
        if(a[1]!=k)
        {
            cout<<0;
            return 0;
        }
        else{
            cout<<1;
            return 0;
        }
    }
    if(n==2)
    {
        int r=a[1] | a[2];
        if(r==k)
        {
            cout<<2;
            return 0;
        }
        else
        {
            if(a[1]==k||a[2]==k)
            {
                cout<<1;
                return 0;
            }
            else
            {
                cout<<0;
                return 0;
            }
        }
    }
    int cnt=0;
    if(d==1)
    {
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) cnt++;
            }
            cout<<cnt;
            return 0;
        }
        else
        {
            cout<<n;
            return 0;
        }
    }
    return 0;
}
