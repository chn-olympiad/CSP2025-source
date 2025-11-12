#include <bits/stdc++.h>
using namespace std;

long long n,k,a[500001]={};

bool check(long long mid)
{
    long long cnt=0,st=1;
    while(cnt<mid&&st<n)
    {
        long long s=a[st];
        if(s==k&&st==n)
        {
            cnt++;
            break;
        }
        for(long long i=st+1;i<=n;i++)
        {
            if(i==n)
            {
               if(s^a[i]==k)
               {
                    st=i;
                    cnt++;
                    break;
               }
               else
               {
                   st=n-mid+1;
                   break;
               }
            }
            if(s==k)
            {
                st=i;
                cnt++;
                break;
            }
            s^=a[i];
        }
    }
    if(cnt>=mid) return 1;
    return 0;
}


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1) flag=0;
    }
    if(flag)
    {
        cout<<n/2;
        return 0;
    }
    bool flag1=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=0&&a[i]!=1) flag=0;
    }
    if(flag1)
    {
        if(k==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0||a[i]==1&&a[i-1]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    long long l=1,r=n;
    while(l<r)
    {
        long long mid=(l+r)/2+1;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
