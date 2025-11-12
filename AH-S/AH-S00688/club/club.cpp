#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,an,bn,cn,k,ans=0,ca[20001],cb[20001],cc[20001];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int u=1;u<=t;u++)
    {
        int k=0;
        int ans=0;
        an=0,bn=0,cn=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            ans+=max(max(a,b),c);
            if((a>b)&&(a>c)&&(b!=c))
            {
                an++;
                ca[a-max(b,c)]++;
            }
            if((b>a)&&(b>c)&&(a!=c))
            {
                bn++;
                cb[b-max(a,c)]++;
            }
            if((c>a)&&(c>b)&&(a!=b))
            {
                cn++;
                cc[c-max(b,a)]++;
            }
            if(b==c)
            {
                if(a<=b)
                {
                    bn++;
                    cb[b-a]++;
                }
                if(a>b)
                {
                    an++;
                    ca[a-b]++;
                }
            }
            if(a==b)
            {
                if(c<a)
                {
                    an++;
                    ca[a-c]++;
                }
                if(c>a)
                {
                    cn++;
                    cc[c-a]++;
                }
            }
            if(a==c)
            {
                if(b<a)
                {
                    an++;
                    ca[a-b]++;
                }
                if(b>a)
                {
                    bn++;
                    cb[b-a]++;
                }
            }
        }
        if(an>(n/2))
        {
            int time=an-n/2;
            for(int i=0;i<=20000;i++)
            {
                if(ca[i]>0)
                {
                    while((k<time)&&(ca[i]>0))
                    {
                        k++;
                        ans-=i;
                        ca[i]--;
                    }
                }
                if(k==time) break;
            }
        }
        if(bn>(n/2))
        {
            int time=bn-n/2;
            for(int i=0;i<=20000;i++)
            {
                if(cb[i]>0)
                {
                    while((k<time)&&(cb[i]>0))
                    {
                        k++;
                        ans-=i;
                        cb[i]--;
                    }
                }
                if(k==time) break;
            }
        }
        if(cn>(n/2))
        {
            int time=cn-n/2;
            for(int i=0;i<=20000;i++)
            {
                if(cc[i]>0)
                {
                    while((k<time)&&(cc[i]>0))
                    {
                        k++;
                        ans-=i;
                        cc[i]--;
                    }
                }
                if(k==time) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
