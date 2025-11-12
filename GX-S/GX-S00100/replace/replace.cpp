#include<iostream>
#include<cstring>
#include<vector>
#define L long long
using namespace std;
constexpr int Mn=2e5+11,Mn2=5e6+11,M=1e9+7,B=13331;
struct I
{
    int l;
    L C1,C2;
    bool operator < (const I& k)const
    {
        return l<k.l;
    }
};
int n,Q,m;
L He2(char *c)
{
    int i;
    L x=0;
    for(i=1;i<=m;i++)x=(x*B%M+c[i]-'a'+1)%M;
    return x;
}
char S1[Mn2],S2[Mn2];
vector<I> H[26][26];
L P[Mn2],H1[Mn2],H2[Mn2];
L He_T1(int a,int b)
{
    return (H1[b]-H1[a-1]*P[b-a+1]%M+M)%M;
}
L He_T2(int a,int b)
{
    return (H2[b]-H2[a-1]*P[b-a+1]%M+M)%M;
}
L g;
int main()
{//      Important
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,zuo,you;
    P[0]=1;
    for(i=1;i<Mn2;i++)P[i]=P[i-1]*B%M;
    cin>>n>>Q;
    for(i=1;i<=n;i++)
    {
        cin>>S1+1>>S2+1;
        m=strlen(S1+1);
        H[S1[1]-'a'][S2[1]-'a'].push_back({m,He2(S1),He2(S2)});
    }
    while(Q--)
    {
        cin>>S1+1>>S2+1;
        m=strlen(S1+1);
        for(i=1;i<=m;i++)H1[i]=(H1[i-1]*B+S1[i]-'a'+1)%M;
        for(i=1;i<=m;i++)H2[i]=(H2[i-1]*B+S2[i]-'a'+1)%M;
        zuo=1;
        you=m;
        while(S1[zuo]==S2[zuo])zuo++;
        while(S1[you]==S2[you])you--;
        g=0;
        for(i=1;i<=zuo;i++)
        {
            for(auto &h:H[S1[i]-'a'][S2[i]-'a'])
                if(i+h.l-1>=you&&i+h.l-1<=m)
                {
                    if(He_T1(i,i+h.l-1)==h.C1&&He_T2(i,i+h.l-1)==h.C2)g++;
                }
        }
        cout<<g<<'\n';
    }
    return 0;
}
