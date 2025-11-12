#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int iii=1;iii<=t;iii++)
    {
        int n,c1=0,a1=0,c2=0,a2=0,c3=0,a3=0;
        cin>>n;
        int s1[n+1],s2[n+1],s3[n+1];
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        memset(s3,0,sizeof(s3));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&s1[i],&s2[i],&s3[i]);
            if(s1[i]>=max(s2[i],s3[i]))
            {
                c1++;
                a1+=s1[i];
            }
            else if(s2[i]>=max(s1[i],s3[i]))
            {
                c2++;
                a2+=s2[i];
            }
            else
            {
                c3++;
                a3+=s3[i];
            }
            //cout<<c1<<' '<<c2<<' '<<c3<<endl;
        }
        int ans=a1+a2+a3;
        if(c1<=n/2&&c2<=n/2&&c3<=n/2)
        {
            cout<<ans<<endl;
        }
        else
        {
            int ext=max(c1,max(c2,c3));
            int rem=ext-n/2;
            int s[n+1];
            memset(s,0,sizeof(s));
            if(ext==c1)
            {
                for(int i=1;i<=n;i++)
                {
                    s[i]=min(s1[i]-s2[i],s1[i]-s3[i]);
                    if(s[i]<0)
                        s[i]=32767;
                }
            }
            else if(ext==c2)
            {
                for(int i=1;i<=n;i++)
                {
                    s[i]=min(s2[i]-s1[i],s2[i]-s3[i]);
                    if(s[i]<0)
                        s[i]=32767;
                }
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    s[i]=min(s3[i]-s1[i],s3[i]-s2[i]);
                    if(s[i]<0)
                        s[i]=32767;
                }
            }
            sort(s,s+n);
            for(int i=1;i<=rem;i++)
            {
                if(s[i]!=32767)
                    ans-=s[i];
            }
            /*
            pair<int,int> ap[n+1];
            int sf[n*2+1],st[n*2+1];
            memset(sf,0,sizeof(sf));
            memset(st,0,sizeof(st));
            memset(ap,0,sizeof(ap));
            if(ext==c1)
            {
                for(int i=1;i<=n;i++)
                {
                    sf[i]=s2[i]-s1[i];
                    sf[i+n]=s3[i]-s1[i];
                    st[i]=sf[i];
                    ap[i].first=sf[i];
                    ap[i].second=sf[i+n];
                }
            }
            else if(ext==c2)
            {
                for(int i=1;i<=n;i++)
                {
                    sf[i]=s1[i]-s2[i];
                    sf[i+n]=s3[i]-s2[i];
                    st[i]=sf[i];
                    ap[i].first=sf[i];
                    ap[i].second=sf[i+n];
                }
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    sf[i]=s1[i]-s3[i];
                    sf[i+n]=s2[i]-s3[i];
                    st[i]=sf[i];
                    ap[i].first=sf[i];
                    ap[i].second=sf[i+n];
                }
            }
            sort(sf,sf+(n*2+1));
            for(int i=1;i<=rem;i++)
            {
                if(sf[i]<=0)
                    ans+=sf[i];
            }
            */
            cout<<ans<<endl;
        }
    }
    return 0;
}
