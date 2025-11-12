#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[5141],b[5141];
int n;ll cn;
bool can(int b,int s[])
{
    int maxn=0,cnt=0;
    for(int i=1;i<=b;i++)
    {
        if(s[i]>maxn)maxn=s[i];
        cnt+=s[i];
    }
    if(cnt>2*maxn)return 1;
    else return 0;
}
void bushi(int i,int j,int d)
{
    if(i==j)
    {
        for(int k=d+1;k<=n;k++)
        {
            b[j]=a[k];
            if(can(i,b))cn++;
        }
    }
    else 
    for(int k=d+1;k<=n;k++)
    {
        b[j]=a[k];
        bushi(i,j+1,k);
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
        bushi(i,1,0);
    }
    cout<<cn%998244353;
    return 0;
}