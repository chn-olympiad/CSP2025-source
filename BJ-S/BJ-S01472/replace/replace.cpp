#include<bits/stdc++.h>
using namespace std;
struct node{
    string f,e;
}a[200007],b[200007];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].f>>a[i].e;
    }
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        cin>>b[i].f>>b[i].e;
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<b[i].f.size()-a[j].f.size()+1;k++)
            {
                bool fg=1;
                string s2=b[i].f;
                for(int l=k;l<=k+a[j].f.size()-1;l++)
                {
                    s2[l]=a[j].e[l-k];
                    if(a[j].f[l-k]!=b[i].f[l])
                    {
                        fg=0;
                    }
                }
                if(fg)
                {

                    if(s2==b[i].e)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
