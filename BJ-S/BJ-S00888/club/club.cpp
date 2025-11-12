#include <bits/stdc++.h>
using namespace std;
int g[100005],t[100005],j[5],o[100005],p[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--)
    {
        memset(g,0,sizeof(g));
        memset(t,0,sizeof(t));
        memset(o,0,sizeof(o));
        p[1]=p[2]=p[3]=0;
        int n,ans=0; cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b,c; cin>>a>>b>>c;
            if(a>b and b>c) g[i]=a-b,t[i]=1,p[1]++;
            if(b>a and a>c) g[i]=b-a,t[i]=2,p[2]++;
            if(b>c and c>a) g[i]=b-c,t[i]=2,p[2]++;
            if(a>c and c>b) g[i]=a-c,t[i]=1,p[1]++;
            if(c>b and b>a) g[i]=c-b,t[i]=3,p[3]++;
            if(c>a and a>b) g[i]=c-a,t[i]=3,p[3]++;
            if(c>a and a==b) g[i]=c-a,t[i]=3,p[3]++;
            if(b>c and c==a) g[i]=b-a,t[i]=2,p[2]++;
            if(a>b and c==b) g[i]=a-c,t[i]=1,p[1]++;
            ans+=max(a,max(b,c));
        }
        //cout<<p[1]<<" "<<p[2]<<" "<<p[3]<<" "<<ans<<endl;
        int cn=0;
        if(p[1]>n/2) for(int i=1;i<=n;i++) if(t[i]==1) o[++cn]=g[i];
        if(p[2]>n/2) for(int i=1;i<=n;i++) if(t[i]==2) o[++cn]=g[i];
        if(p[3]>n/2) for(int i=1;i<=n;i++) if(t[i]==3) o[++cn]=g[i];
        sort(o+1,o+cn+1);
        for(int i=1;i<=max(p[1],max(p[2],p[3]))-n/2;i++) ans-=o[i];
        cout<<ans<<endl;
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
