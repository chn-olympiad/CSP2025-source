#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t1,t2,t3;
int d[N];
struct node
{
    int a1,a2,a3;
}s[N];
int n;
long long ans;
void dfs(int n,int deep,int w1,int w2,int w3,long long mayi)
{
    //cout<<"yes";
    if(deep==n+1)
    {
        ans=max(ans,mayi);
        return ;
    }
    else
    {

            if(w1<=n/2-1)
            {
                d[deep]=1;
                dfs(n,deep+1,w1+1,w2,w3,mayi+s[deep].a1);
            }
            if(w2<=n/2-1)
            {
                d[deep]=2;
                dfs(n,deep+1,w1,w2+1,w3,mayi+s[deep].a2);
            }
            if(w3<=n/2-1)
            {
                d[deep]=3;
                dfs(n,deep+1,w1,w2,w3+1,mayi+s[deep].a3);
            }

    }
}
long long figure(int n)
{
    for(int i=1;i<=n;++i)
            {
                if(d[i]==1) ans+=s[i].a1;
                if(d[i]==2) ans+=s[i].a2;
                if(d[i]==3) ans+=s[i].a3;
            }
            return ans;
}
bool cmp1_mxx(node x,node y)
{
    return x.a1>=y.a1;

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        bool flaga=1,flagb=1;
        for(int i=1;i<=n;++i)
        {
            cin>>s[i].a1>>s[i].a2>>s[i].a3;
            if(s[i].a2!=0 ||s[i].a3!=0 ) flaga=0;
            if(s[i].a3!=0) flagb=0;
            int ac=max(s[i].a1,s[i].a2);
            ac=max(ac,s[i].a3);
            if(ac==s[i].a1)
            {
                d[i]=1;
                t1++;
            }
            if(ac==s[i].a2){
                d[i]=2;
                t2++;
            }
            if(ac==s[i].a3)
            {
                d[i]=3;
                t3++;}
        }
        if(flaga==1)
        {
            sort(s,s+1+n,cmp1_mxx);
            for(int i=1;i<=n/2;++i)
            {
                ans+=s[i].a1;
            }
            cout<<ans<<endl;
            continue;
        }
        if(t1<=n/2 && t2<=n/2 && t3<=n/2)
        {
            cout<<figure(n)<<endl;
            continue;
        }
        dfs(n,1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
