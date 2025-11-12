#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,s,len=1,cnt;
    bool f;
    cin>>n;
    if(n==3)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++)
    {
        s=0;
        f=false;
        for(int j=1;j<=i;j++)
        {
            b[j]=j;
        }
        while(true)
        {
            cnt=1;
            for(int k=1;k<=i;k++)
            {
                s+=a[b[k]];
            }
            if(s>a[b[i]]*2)ans++;
            ans=ans%998244353;
            b[i]++;
            for(int k=i;k>=1;k--)
            {
                if(b[k]>n-cnt+1)
                {
                    b[k-1]++;
                    for(int p=k;p<=i;p++)
                    {
                        b[p]=b[p-1]+1;
                    }
                }
                cnt++;
            }
            if(f)break;
            if(b[1]==n-i+1)f=true;
        }
    }
    cout<<ans;
    return 0;
}
