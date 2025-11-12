#include<bits/stdc++.h>
using namespace std;
#define int long long
string l,r,l1,l2,k1,k2,o1,o2;
int n,m,i,j,k,ans,t,q[200004],w[200004];
map<pair<string,string>,int> s;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++){
        cin>>l>>r;
        s[{l,r}]=1;
    }
    for(i=1;i<=m;i++){
        cin>>l>>r;
        ans=0;
        t=l.length();
        k1=k2=o1=o2="";
        for(j=0;j<t;j++){
            k1+=r[j];
            k2+=l[j];
            q[j]=(k1==k2);
        }
        for(j=t-1;j>=0;j--){
            o1+=r[j];
            o2+=l[j];
            w[j]=(o1==o2);
        }
        for(j=0;j<t;j++){
            l1=l2="";
            for(k=j;k<t;k++){
                l1+=l[k];
                l2+=r[k];
                if(j!=0&&k!=t) ans+=(s[{l1,l2}]&&w[k+1]&&q[j-1]);
                else if(j!=0) ans+=(s[{l1,l2}]&&q[j-1]);
                else if(k!=t) ans+=(s[{l1,l2}]&&w[k+1]);
                else ans+=s[{l1,l2}];
            }
        }
        printf("%lld\n",ans);
    }
}