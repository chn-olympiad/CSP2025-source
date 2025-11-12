#include<bits/stdc++.h>
#define Std_Maker lhm
#define ll long long
#define ull unsigned long long
using namespace std;
const int base=233,N=2e5+1,M=5e6+1;
ll n,q,ans;
string s1[N],s2[N],q1,q2;
ull h1[M],p1[M],h2[M],p2[M],h3[M],p3[M],h4[M],p4[M];
void makehash(string s,ull h[],ull p[])
{
    p[0]=1;
    ll l=s.length()-1;
    for(int i=1;i<=l;i++)
    {
        h[i]=h[i-1]*base+s[i];
        p[i]=p[i-1]*base;
    }
    return;
}
ll gethash(string s,ull h[],ull p[],ll l,ll r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        s1[i]=" "+s1[i],s2[i]=" "+s2[i];
    }
    while(q--)
    {
        ans=0;
        cin>>q1>>q2;
        if(q1.length()!=q2.length())
        {
            cout<<0<<endl;
            continue;
        }
        q1=" "+q1,q2=" "+q2;
        makehash(q1,h1,p1);
        makehash(q2,h2,p2);
        for(int i=1;i<=n;i++)
        {
            makehash(s1[i],h3,p3);
            makehash(s2[i],h4,p4);
            ll l=s1[i].length()-1,lm=q1.length()-1;
            for(int j=1;j<=lm-l+1;j++)
            {
                if(gethash(q1,h1,p1,j,j+l-1)==gethash(s1[i],h3,p3,1,l) and gethash(q2,h2,p2,j,j+l-1)==gethash(s2[i],h4,p4,1,l))
                {
                    if(gethash(q1,h1,p1,1,j-1)==gethash(q2,h2,p2,1,j-1) and gethash(q1,h1,p1,j+l,lm)==gethash(q2,h2,p2,j+l,lm))
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
//2h37min 25pts?
