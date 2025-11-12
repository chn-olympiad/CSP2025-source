#include<bits/stdc++.h>
using namespace std; 
bool vis[500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    long long int a[n+1],cnt1=0,cnt2=0,cnt3=0;
    bool b=0,c=0,d=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]==k) vis[i]=1,cnt3++;
        if(a[i]>1) b=1;
        if(a[i]==0) c=1;
    }
    if(c==0&&b==0) cout<<n/2;
    if(b==0&&c==1)
    {
        for(int i=1;i<=n;i++) if(a[i]==0) cnt1++;
        if(k==0) cout<<cnt1;
        else cout<<n-cnt1;
    }
    if(b==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==1) {cnt2=-1;continue;}
            if(cnt2==-1) cnt2=a[i];
            else cnt2=cnt2^a[i];
            if(cnt2==k) cnt3++,cnt2=-1;
        }
        cout<<cnt3;
    }
    return 0;
}

