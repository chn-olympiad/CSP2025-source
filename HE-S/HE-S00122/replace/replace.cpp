#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int P=13331;
ull p[5000005];
ull has1[5000005],has2[5000005];
int n,q;
string s1,s2;
map<pair<ull,ull>,int>mp1,mp2;
ull get_hash(int l,int r,ull has[])
{
    return has[r]-has[l-1]*p[r-l+1];
}
void work(string a,string b,int lena,int lenb)
{
    int maxl=1,minr=lena,res=0;
    // for(int i=0;i<lena;i++) has1[i]=has2[i]=0;
    for(int i=1;i<=lena;i++) has1[i]=has1[i-1]*P+a[i-1];
    for(int i=1;i<=lenb;i++) has2[i]=has2[i-1]*P+b[i-1];
    while(a[maxl-1]==b[maxl-1]) maxl++;
    while(a[minr-1]==b[minr-1]) minr--;
    if(!mp2.count({get_hash(maxl,minr,has1),get_hash(maxl,minr,has2)}))
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<=maxl;i++)
    {
        for(int j=lena;j>=max(i,minr);j--)
        {
            ull x=get_hash(i,j,has1);
            ull y=get_hash(i,j,has2);
            if(mp1.count({x,y})) res+=mp1[{x,y}];
        }
    }
    cout<<res<<'\n';
    return;
}
void chuli(string a,string b,int lena)
{
     int maxl=1,minr=lena,res=0;
    // for(int i=0;i<lena;i++) has1[i]=has2[i]=0;
    for(int i=1;i<=lena;i++) has1[i]=has1[i-1]*P+a[i-1];
    for(int i=1;i<=lena;i++) has2[i]=has2[i-1]*P+b[i-1];
    while(a[maxl-1]==b[maxl-1]) maxl++;
    while(a[minr-1]==b[minr-1]) minr--;
    mp2[{get_hash(maxl,minr,has1),get_hash(maxl,minr,has2)}]++;
}
ull Hash(string a)
{
    ull res=0;
    int len=a.length();
    for(int i=0;i<len;i++)
        res=res*P+a[i];
    return res;
}
signed main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    p[0]=1;
    for(int i=1;i<=5000000;i++) p[i]=p[i-1]*P; 
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        mp1[{Hash(s1),Hash(s2)}]++;
        chuli(s1,s2,s1.length());
    }
    string t1,t2;
    for(int i=1;i<=q;i++)
    {
        int len1=0,len2=0;
        cin>>t1>>t2;
        len1=t1.length();
        len2=t2.length();
        if(len1!=len2)
        {
            cout<<0<<'\n';
            continue;
        }
        work(t1,t2,len1,len2);
    }
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
