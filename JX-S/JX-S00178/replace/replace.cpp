#include<bits/stdc++.h>
using namespace std;
int t;
long long n,q;
unordered_map<string,string>m;
void solve()
{
    string a,b;cin>>a>>b;
    long long l,r,ans=0;
    for(long long i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            l=i;
            break;
        }
    }
    for(long long i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            r=i;
            break;
        }
    }
    for(long long l2=l;l2>=0;l2--)
    {
        for(long long r2=r;r2<=a.size()-1;r2++)
        {
            long long len=r2-l2+1;
            string h=a.substr(l2,len);
            //cout<<l2<<" "<<r2<<" "<<len<<"\n";
            if(m.count(h))
            {
                string h2=b.substr(l2,len);
                if(h2==m[h])
                {
                    ans++;
                }
                //cout<<h<<" "<<h2<<" "<<m[h]<<"\n";
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        m[a]=b;
    }
    while(q--)
    {   /*if(n<=100)*/
        solve();
        //solve2();
    }
    return 0;
}
