#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,l[200005],len,pi[10000005],ans;
string a1[200005],a2[200005],q1,q2,str;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
    {
        cin>>a1[i]>>a2[i];
        l[i]=a1[i].size();
    }
    while(q--)
    {
        ans=0;
        cin>>q1>>q2;
        len=q1.size();
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<=l[i]+len;j++) pi[i]=0;
            str=" "+a1[i]+"&"+q1;
            for(ll j=2,k;j<=l[i]+len+1;j++)
            {
                pi[j]=0;
                k=j-1;
                while(str[j]!=str[pi[k]+1]&&k!=0) k=pi[k];
                if(str[j]==str[pi[k]+1]) pi[j]=pi[k]+1;
            }
            string re=q1,ree=q1;
            for(ll j=l[i]+1;j<=l[i]+len+1;j++)
            {
                re=ree;
                if(pi[j]==l[i])
                    for(ll k=0;k<l[i];k++) re[k+j-(l[i]<<1)-1]=a2[i][k];
                if(re==q2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
