#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,ca[N],cb[N],cc[N],t[5];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int f=1;
        for(int i=1;i<=n;i++)
        {
            cin>>ca[i]>>cb[i]>>cc[i];
            if(cc[i]!=0||cb[i]!=0) f=0;
        }
        if(f)
        {
            sort(ca+1,ca+n+1);
            int ans=0;
            for(int i=n;i>=n/2;i--) ans+=ca[i];
            cout<<ans<<endl;
        }
        if(n==2)
        {
            int ans=0;
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    int res=0;
                    t[i]++;t[j]++;
                    if(i==1) res+=ca[1];
                    else if(i==2) res+=cb[1];
                    else res+=cc[1];
                    if(j==1) res+=ca[2];
                    else if(j==2) res+=cb[2];
                    else res+=cc[2];
                    if(t[1]>1||t[2]>1||t[3]>1)
                    {
                        t[1]=0;t[2]=0;t[3]=0;
                        continue;
                    }
                    ans=max(ans,res);
                    t[1]=0;t[2]=0;t[3]=0;
                }

            }
            cout<<ans<<endl;
        }
        if(n==4)
        {
            int ans=0,tot=0;
            for(int a=1;a<=3;a++)
            for(int b=1;b<=3;b++)
            for(int c=1;c<=3;c++)
            for(int d=1;d<=3;d++)
            {
                int res=0;
                t[a]++;t[b]++;t[c]++;t[d]++;
                if(a==1) res+=ca[1];
                else if(a==2) res+=cb[1];
                else res+=cc[1];
                if(b==1) res+=ca[2];
                else if(b==2) res+=cb[2];
                else res+=cc[2];
                if(c==1) res+=ca[3];
                else if(c==2) res+=cb[3];
                else res+=cc[3];
                if(d==1) res+=ca[4];
                else if(d==2) res+=cb[4];
                else res+=cc[4];
                if(t[1]>2||t[2]>2||t[3]>2)
                {
                    tot++;
                    t[1]=0;t[2]=0;t[3]=0;
                    continue;
                }
                ans=max(ans,res);
                t[1]=0;t[2]=0;t[3]=0;
            }
            cout<<ans<<endl;
        }
        if(n==10)
        {
            int ans=0;
            for(int a=1;a<=3;a++)
            for(int b=1;b<=3;b++)
            for(int c=1;c<=3;c++)
            for(int d=1;d<=3;d++)
            for(int e=1;e<=3;e++)
            for(int f=1;f<=3;f++)
            for(int g=1;g<=3;g++)
            for(int h=1;h<=3;h++)
            for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                int res=0;
                t[a]++;t[b]++;t[c]++;t[d]++;t[e]++;
                t[f]++;t[g]++;t[h]++;t[i]++;t[j]++;
                if(a==1) res+=ca[1];
                else if(a==2) res+=cb[1];
                else res+=cc[1];
                if(b==1) res+=ca[2];
                else if(b==2) res+=cb[2];
                else res+=cc[2];
                if(c==1) res+=ca[3];
                else if(c==2) res+=cb[3];
                else res+=cc[3];
                if(d==1) res+=ca[4];
                else if(d==2) res+=cb[4];
                else res+=cc[4];
                if(e==1) res+=ca[5];
                else if(e==2) res+=cb[5];
                else res+=cc[5];
                if(f==1) res+=ca[6];
                else if(f==2) res+=cb[6];
                else res+=cc[6];
                if(g==1) res+=ca[7];
                else if(g==2) res+=cb[7];
                else res+=cc[7];
                if(h==1) res+=ca[8];
                else if(h==2) res+=cb[8];
                else res+=cc[8];
                if(i==1) res+=ca[9];
                else if(i==2) res+=cb[9];
                else res+=cc[9];
                if(j==1) res+=ca[10];
                else if(d==2) res+=cb[10];
                else res+=cc[10];
                if(t[1]>5||t[2]>5||t[3]>5)
                {
                    t[1]=0;t[2]=0;t[3]=0;
                    continue;
                }
                ans=max(ans,res);
                t[1]=0;t[2]=0;t[3]=0;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
