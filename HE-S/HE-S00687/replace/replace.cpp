#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=5e6+10;
const int P=13331;
int n,q;
string s1,s2;
ull hx1[N],hx2[N],p[N];
unordered_map<int,int> mp;

inline ull get_hx1(int l,int r)
{
    return hx1[r]-hx1[l-1]*p[r-l+1];
}

inline ull get_hx2(int l,int r)
{
    return hx2[r]-hx2[l-1]*p[r-l+1];
}

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<N;++i)
        p[i]=p[i-1]*P;
    
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>s1>>s2;
        ull hxs1=0,hxs2=0;
        for(int i=0;i<s1.size();++i)
            hxs1=hxs1*P+(s1[i]-'a'+1);
        for(int i=0;i<s2.size();++i)
            hxs2=hxs2*P+(s2[i]-'a'+1);
        // if(hxs1==2)
            // cout<<"hxxs1="<<hxs1<< " hxs2="<<hxs2<<"\n";
        mp[hxs1]=hxs2;
    }
    while(q--)
    {
        cin>>s1>>s2;
        int op=s2.size(),ed=0,ans=0,len=s1.size();
        s1=" "+s1,s2=" "+s2;
        for(int i=1;i<=len;++i)
        {
            hx1[i]=hx1[i-1]*P+(s1[i]-'a'+1);
            // cout<<"i="<<i<<" hx1="<<hx1[i]<<"\n";
        }
        for(int i=1;i<=len;++i)
        {
            if(s1[i]!=s2[i])
            {
                // cout<<"i="<<i<<"\n";
                op=min(op,i),ed=max(ed,i);
            }
            hx2[i]=hx2[i-1]*P+(s2[i]-'a'+1);
            // cout<<"i="<<i<<" hx2="<<hx2[i]<<"\n";
        }
        // cout<<"op="<<op<<" ed="<<ed<<"\n";
        for(int i=1;i<=op;++i)
        {
            for(int j=ed;j<=len;++j)
            {
                // cout<<"i="<<i<<" j="<<j<<"\n";
                // cout<<"hx1="<<get_hx1(i,j)<<" hx2="<<get_hx2(i,j)<<"\n";
                if(mp[get_hx1(i,j)]==get_hx2(i,j)&&get_hx1(1,max(1ll,i-1))==get_hx2(1,max(1ll,i-1)))
                {
                    if(j==len||get_hx1(j+1,len)==get_hx2(j+1,len))
                    // cout<<"i="<<i<<" j="<<j<<"\n";
                    ++ans;
                }
            }   
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//zhuijile
