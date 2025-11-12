#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base=233;
const ll mod=1e17+3;
int n,q;
char s1[5000005],s2[5000005];
map<ll,multiset<ll> > m;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=1,len;i<=n;++i)
    {
        scanf("%s %s",s1+1,s2+1);
        len=strlen(s1+1);
        ll now1=0,now2=0;
        for(int j=1;j<=len;++j)
        {
            now1=(now1*base+s1[j])%mod;
            now2=(now2*base+s2[j])%mod;
        }
        m[now1].insert(now2);
    }
    while(q--)
    {
        scanf("%s %s",s1+1,s2+1);
        int l=strlen(s1+1),l2=strlen(s2+1);
        if(l!=l2)
        {
            printf("0\n");
            continue;
        }
        int L=l+1,R;
        for(int i=1;i<=l;++i)
        {
            if(s1[i]!=s2[i])
            {
                if(L>l) L=i;
                R=i;
            }
        }
        //printf("%d %d\n",L,R);
        ll ans=0;
        for(int i=1;i<=L;++i)
        {
            ll ha1=0,ha2=0;
            for(int j=i;j<=l;++j)
            {
                ha1=(ha1*base+s1[j])%mod;
                ha2=(ha2*base+s2[j])%mod;
                if(j>=R) ans+=m[ha1].count(ha2);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
