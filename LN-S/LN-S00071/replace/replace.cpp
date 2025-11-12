#include<bits/stdc++.h>
using namespace std;
string a[2000];
string b[2000];
string ca[2000],cb[2000];
string cca[2000],ccb[2000];
string a1,b1;
int n,q;
void so1()
{
    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>a1>>b1;
        if(a1.size()!=b1.size())
            cout<<0<<endl;
        int hb=-1,he=0;
        for(int j=0;j<a1.size();j++)
        {
            if(a1[j]!=b1[j])
            {
                if(hb==-1)
                    hb=j;
                he=j;
            }
        }
        int h=he-hb+1;
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j].size()<h)
            {
                continue;
            }
            else
            {
                int u=0;
                for(int k=0;k<a1.size();k++)
                {
                    if(a1[k]!=a[j][u]||b1[k]!=b[j][u])
                    {
                        u=0;
                    }
                    else
                        u++;
                    if(u==a[j].size())
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

}
void so2()
{
    int aa[100005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='b')
                aa[i]+=j;
            if(b[i][j]=='b')
                aa[i]-=j;
        }
    }
    sort(aa+1,aa+n+1);
    for(int i=1;i<=q;i++)
    {
        cin>>a[i]>>b[i];
        int k=0;
        if(a[i].size()!=b[i].size())
        {
            cout<<0<<endl;
            break;
        }
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='b')
                k+=j;
            if(b[i][j]=='b')
                k-=j;
        }
        int l=0;
        int r=n;
        while(r-l>10)
        {
            int mid=(l+r)/2;
            if(k>aa[mid])
                l=mid;
            else
                r=mid;
        }
        for(int j=l;j<=r;j++)
        {
            if(k==aa[j])
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
                break;
            }
        }
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    if(n<=1000&&q<=1000)
    {
        so1();
    }
    else
    {
        so2();
    }
    return 0;
}
