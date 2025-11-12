#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]; p=max(p,a[i]);
        s[i]=(s[i-1]^a[i]);
    }
    if(n<=1005)
    {
        int used=0,ans=0;
        //for(int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        for(int i=1;i<=n;i++)
            for(int j=i;j>used;j--)
                if((s[i]^s[j-1])==k)
                {
                    //cout<<"Current: "<<(s[i]^s[j-1])<<endl;
                    //cout<<j-1<<": "<<s[j-1]<<" ~ "<<i<<": "<<s[i]<<endl;
                    used=i; ans++;
                }
        cout<<ans<<endl; return 0; //namespace pts60;
    }
    else if(p==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==k) ans++;
            else if(a[i-1]==a[i]&&a[i]==(!k)) ans++,i++;
        }
        cout<<ans<<endl; return 0; //Checting for 5 pts? I also don't know why.
    }
    else if(n<=30005)
    {
        int used=0,ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j>used;j--)
                if((s[i]^s[j-1])==k)
                    used=i,ans++;
        cout<<ans<<endl; return 0; //rp++; CSP_long_long_live++;
    }
    return 0;
}
//O(n^2): 60pts
//O(nlogn): 80pts
//O(n): 100pts
