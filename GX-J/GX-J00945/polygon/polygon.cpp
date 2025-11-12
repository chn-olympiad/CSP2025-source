#include<bits/stdc++.h>
using namespace std;
int arr[5009]={0};
int ans=0;
int ar[5009]={0};
int n;
void fun(int a,int b,int c)
{
    if(b>c)
    {
        int s=0;
        for(int i=1;i<=c;i++)
            s+=ar[i];
        if(s>ar[c]*2)
            ans++;
        ans%=998244353;
        return ;
    }
    for(int i=a;i<=n;i++)
    {
        ar[b]=arr[i];
        fun(i+1,b+1,c);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=3;i<=n;i++)
        fun(1,1,i);
    cout<<ans;
    return 0;
}
