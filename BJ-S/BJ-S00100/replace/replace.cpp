#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5,P=27;
int n,q,tot,uselen[N],len[N],num[N],ans;
unsigned int uses1[N],uses2[N],s1[N],s2[N],h1[M],h2[M],p[M];
inline bool ss(int lenn,int x,int y,unsigned int w1,unsigned int w2)
{
    if(h1[x+y-1]-h1[x-1]*p[y]!=w1)
    {
        return 0;
    }
    if(h1[lenn]+(w2-w1)*p[lenn-x-y+1]!=h2[lenn])
    {
        return 0;
    }
    return 1;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p[0]=1;
    for(int i=1;i<M;i++)
    {
        p[i]=p[i-1]*P;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a1,a2;
        cin>>a1>>a2;
        len[i]=a1.size();
        for(int j=0;j<len[i];j++)
        {
            s1[i]*=P;
            s2[i]*=P;
            s1[i]+=a1[j]-'a'+1;
            s2[i]+=a2[j]-'a'+1;
            if(a1[j]!=a2[j])
            {
                num[i]++;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int lenq,minn=INT_MAX,numcnt=0,ll=0,rr=0;
        string a1,a2;
        cin>>a1>>a2;
        if(a1.size()!=a2.size())
        {
            cout<<0<<endl;
            continue;
        }
        lenq=a1.size();
        for(int j=0;j<lenq;j++)
        {
            h1[j+1]=h1[j]*P+a1[j]-'a'+1;
            h2[j+1]=h2[j]*P+a2[j]-'a'+1;
            if(a1[j]!=a2[j])
            {
                numcnt++;
                if(!ll)
                {
                    ll=j+1;
                }
                rr=j+1;
            }
        }
        tot=0;
        for(int j=1;j<=n;j++)
        {
            if(num[j]==numcnt&&len[j]>=rr-ll+1&&len[j]<=lenq)
            {
                uselen[++tot]=len[j];
                uses1[tot]=s1[j];
                uses2[tot]=s2[j];
                minn=min(minn,len[j]);
            }
        }
        ans=0;
        if(!tot)
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=1;j<=lenq-minn+1;j++)
        {
            for(int k=1;k<=tot;k++)
            {
                if(j+uselen[k]-1<=lenq&&ss(lenq,j,uselen[k],uses1[k],uses2[k]))
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}