#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=2e6+10;
int n,q;
struct Astring{
    string str;
    vector<int> hyh1;
    vector<int> hyh2;
}s1[Maxn],s2[Maxn],q1[Maxn],q2[Maxn];

int qpow(int a,int b,int md)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res=res*a%md;
        }
        a=a*a%md;
        b>>=1;
    }
    return res;
}

// hash1
const int Base1=17;
const int Mod1=1e9+7;
int fac1[Maxn];
void init1()
{
    fac1[0]=1;
    for(int i=1;i<=200000;i++)
    {
        fac1[i]=fac1[i-1]*Base1%Mod1;
    }
}
vector<int> gethash1(string str)
{
    vector<int> ans;
    ans.push_back(str[0]-'a'+1);
    for(int i=1;i<str.size();i++)
    {
        ans.push_back((ans[i-1]*Base1%Mod1+str[i]-'a'+1)%Mod1);
    }
    /*
    cout<<"hash sequence:"<<endl;
    for(auto j:ans)
    {
        cout<<j<<" "<<endl;
    }*/
    return ans;
}
int getLR1(Astring s,int l,int r)
{
    string str=s.str;
    // [l,r] (l,r\in [0,n-1])
    if(l==0) return s.hyh1[r];
    int vr=s.hyh1[r],vl=s.hyh1[l-1];
    //cout<<"getLR:"<<l<<","<<r<<endl;
    //cout<<"fac="<<fac1[r-l-1]<<endl;
    return (vr%Mod1-vl*fac1[(r-l+1)]%Mod1+Mod1)%Mod1;
}

// hash2
const int Base2=13;
const int Mod2=19260817;
int fac2[Maxn];
void init2()
{
    fac2[0]=1;
    for(int i=1;i<=200000;i++)
    {
        fac2[i]=fac2[i-1]*Base2%Mod2;
    }
}
vector<int> gethash2(string str)
{
    vector<int> ans;
    ans.push_back(str[0]-'a'+1);
    for(int i=1;i<str.size();i++)
    {
        ans.push_back((ans[i-1]*Base2%Mod2+str[i]-'a'+1)%Mod2);
    }
    return ans;
}
int getLR2(Astring s,int l,int r)
{
    string str=s.str;
    // [l,r] (l,r\in [0,n-1])
    if(l==0) return s.hyh2[r];
    int vr=s.hyh2[r],vl=s.hyh2[l-1];
    return (vr%Mod1-vl*fac2[(r-l+1)]%Mod2+Mod2)%Mod2;
}
struct Pair{
    pair<int,int> p1;
    pair<int,int> p2;
    bool operator<(const Pair &rhs)const{
        return 1;
    }
};
#define pii pair<int,int>
#define MP make_pair
map<pair<pii,pii>,int> mp;

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    init1();
    init2();
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i].str>>s2[i].str;
        int l=s1[i].str.size();
        s1[i].hyh1=gethash1(s1[i].str);
        s1[i].hyh2=gethash2(s1[i].str);
        s2[i].hyh1=gethash1(s2[i].str);
        s2[i].hyh2=gethash2(s2[i].str);
        //cout<<s1[i].hyh1[l-1]<<" "<<s2[i].hyh1[l-1]<<endl;
        //cout<<s1[i].hyh2[l-1]<<" "<<s2[i].hyh2[l-1]<<endl;
        //cout<<endl;
        pair<pii,pii> tmp=MP(MP(s1[i].hyh1[l-1],s2[i].hyh1[l-1]),MP(s1[i].hyh2[l-1],s2[i].hyh2[l-1]));
        if(mp[tmp]==0) mp[tmp]=1;
        else mp[tmp]++;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>q1[i].str>>q2[i].str;
        q1[i].hyh1=gethash1(q1[i].str);
        q1[i].hyh2=gethash2(q1[i].str);
        q2[i].hyh1=gethash1(q2[i].str);
        q2[i].hyh2=gethash2(q2[i].str);
        int l=q1[i].str.size();

        if(l>=5000)
        {
            puts("0");
            continue;
        }
        int ans=0;
        for(int j=0;j<l;j++)
        {
            for(int k=l-1;k>0;k--)
            {
                int L=j,R=k;
                int v1=getLR1(q1[i],L,R),v2=getLR1(q2[i],L,R);
                int v3=getLR2(q1[i],L,R),v4=getLR2(q2[i],L,R);
                /*
                cout<<"L="<<L<<",R="<<R<<endl;
                cout<<"v1="<<v1<<",v2="<<v2<<endl;
                cout<<"v3="<<v3<<",v4="<<v4<<endl;
                cout<<"res+"<<mp[MP(MP(v1,v2),MP(v3,v4))]<<endl;
                */
                ans+=mp[MP(MP(v1,v2),MP(v3,v4))];
                if(q1[i].str[k]!=q2[i].str[k]) break;
            }
            if(q1[i].str[j]!=q2[i].str[j]) break;;
        }

        printf("%lld\n",ans);
    }


    return 0;
}
