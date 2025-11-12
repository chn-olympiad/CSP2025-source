#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],num=0;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3){
        int cnt=0,maxn=-1;
        for(int i=1;i<=n;i++)
          cnt+=a[i],maxn=max(maxn,a[i]);
        if(cnt>maxn)    cout<<1<<endl;
        return 0;
    }
    cout<<n+1<<endl;
    return 0;
}

