#include <iostream>
using namespace std;
string s1,s2;
int l[200005],mod=1e9+7,p=10009;
long long q1[200005],q2[200005],h[5000005],ci[5000005];
int gethash(int l,int r)
{
    if(l==0)return h[r];
    return (h[r]-h[l-1]*ci[r-l+1]%mod+mod)%mod;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,q,l1,l2,ans,i,j;
    long long ha,dq;
    cin>>n>>q;
    ci[0]=1;
    for(i=1;i<=5000000;i++)
        ci[i]=ci[i-1]*p%mod;
    for(i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        l[i]=s1.size();
        for(j=0;j<l[i];j++)
        {
            q1[i]=(q1[i]*p%mod+s1[j]-'0')%mod;
            q2[i]=(q2[i]*p%mod+s2[j]-'0')%mod;
        }
    }
    while(q--)
    {
        cin>>s1>>s2;
        l1=s1.size(),l2=s2.size();
        if(l1!=l2)
        {
            cout<<"0\n";
            continue;
        }
        h[0]=s1[0]-'0';
        ha=s2[0]-'0';
        for(i=1;i<l1;i++)
        {
            h[i]=(h[i-1]*p%mod+s1[i]-'0')%mod;
            ha=(ha*p%mod+s2[i]-'0')%mod;
        }
        ans=0;
        for(i=0;i<l1;i++)
            for(j=1;j<=n;j++)
            {
                if(i+l[j]>l1||gethash(i,i+l[j]-1)!=q1[j])continue;
                if(i!=0)
                    dq=gethash(0,i-1)*ci[l1-i]%mod;
                dq=(dq+q2[j]*ci[l1-i-l[j]%mod])%mod;
                if(i+l[j]<l1)
                    dq=(dq+gethash(i+l[j],l1-1))%mod;
                if(dq==ha)
                    ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}