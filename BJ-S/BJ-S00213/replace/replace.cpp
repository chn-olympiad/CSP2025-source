#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2e5+5;
int n,q,as[N],to[10000010],L1,L2,cnt0,hs[1005][3][2005],ht1[2005],P[1000],ht2[20045];
bool ck;
string s[N][3],t1,t2;
/*inline void has()
{
    for(int j=1;j<=n;j++)
    {
        int l1=s[j][1].size(),l2=s[j][2].size();
        for(int i=0;i<l1;i++)
        {
            h[j][1][i]=s[j][1][i]+h[j][1][i-1]*p;
        }
        for(int i=0;i<l2;i++)
        {
            h[j][2][i]=s[j][2][i]+h[j][2][i-1]*p;
        }   
    }
    for(int i=1;i<=1000;i++)
    {

    }
}*/
inline void solve2()
{
    for(int i=1;i<=n;i++)
    {
        int l1=s[i][1].size(),l2=s[i][2].size(),cur1,cur2;
        for(int j=0;j<l1;j++)
        {
            if(s[i][1][j]=='b') 
            {
                cur1=j+1;
                break;
            }
        }
        for(int j=0;j<l2;j++)
        {
            if(s[i][2][j]=='b')
            {
                cur2=j+1;
                break;
            } 
        }
        to[cur1-cur2+5000000]++;
    }
    while(q--)
    {
        cin>>t1>>t2;
        int l1=t1.size(),l2=t2.size(),cur1,cur2;
        for(int i=0;i<l1;i++)
        {
            if(t1[i]=='b') cur1=i+1;
        }
        for(int i=0;i<l2;i++)
        {
            if(t2[i]=='b') cur2=i+1;
        }   
        cout<<to[cur1-cur2+5000000]<<endl;
    }
    exit(0);
}
inline void solve1()
{
    if(L1>2000)

    exit(0);
}

signed main()
{   
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
       /* int l1=s[i][1].size(),l2=s[i][2].size(),cur1,cur2;
        cnt0=0;
        for(int j=0;j<l1;j++)
        {
            if(s[i][1][j]!='a'&&s[i][1][j]!='b')
            {
                ck=true;
                break;
            } 
            if(s[i][1][j]=='b') cnt0++;
        }
        if(cnt0!=1) ck=true;
        if(ck) break;
        cnt0=0;
        for(int j=0;j<l2;j++)
        {
            if(s[i][2][j]!='b'&&s[i][2][j]!='a') 
            {
                ck=true;
                break;
            }
            if(s[i][2][j]=='b') cnt0++;
        }
        if(cnt0!=1) ck=true;*/
    }
    solve2();
  /*  has();
    while(q--)
    {
        cin>>t1>>t2;
        int l1=t1.size(),l2=t2.size();
        for(int i=0;i<l1;i++)
        {
            ht1[i]=ht1[i-1]*p+t1[i];
        }
        for(int i=0;i<l2;i++)
        {
            ht2[i]=ht2[i-1]*p+t2[i];
        }
        for(int j=1;j<=n;j++)
        {
            for(int i=s[j][1].size()-1;i<l1;i++)
            {
                if(hs[j][1][s[j][1].size()]==ht1[i]-)
                {

                }
            }   
        }
    }*/
    return 0;
}