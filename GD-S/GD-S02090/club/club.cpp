#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
const int _mxn=1e5+5;
int max3(int a,int b,int c){return max(a,max(b,c));}
int min3(int a,int b,int c){return min(a,min(b,c));}
int mid3(int a,int b,int c)
{
    int mx=max3(a,b,c),mn=min3(a,b,c);
    if(a==mx&&b==mn||a==mn&&b==mx)
        return c;
    if(a==mx&&c==mn||a==mn&&c==mx)
        return b;
    if(b==mx&&c==mn||b==mn&&c==mx)
        return a;
}
struct node
{
    int a1,a2,a3;
    bool operator<(node _x) const
    {
        int mn=min3(a1,a2,a3),mnx=min3(_x.a1,_x.a2,_x.a3);
        return max3(a1-mn,a2-mn,a3-mn)>max3(_x.a1-mnx,_x.a2-mnx,_x.a3-mnx);
    }
}a[_mxn];
int n;
// ll ans=0;
// void dfs(int dep,int s1,int s2,int s3,ll s)
// {
//     if(dep>n)
//     {
//         ans=max(ans,s);
//         return;
//     }
//     if(s1<n/2)
//         dfs(dep+1,s1+1,s2,s3,s+a[dep].a1);
//     if(s2<n/2)
//         dfs(dep+1,s1,s2+1,s3,s+a[dep].a2);
//     if(s3<n/2)
//         dfs(dep+1,s1,s2,s3+1,s+a[dep].a3);
// }
vector<int> d1,d2,d3;
bool cmp(int i,int j)
{
    return max3(a[i].a1,a[i].a2,a[i].a3)-mid3(a[i].a1,a[i].a2,a[i].a3)<max3(a[j].a1,a[j].a2,a[j].a3)-mid3(a[j].a1,a[j].a2,a[j].a3);
}
int main()
{
    ___();
    int _;
    cin>>_;
    while(_--)
    {
        cin>>n;
        ll ans=0;
        d1.clear(),d2.clear(),d3.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            int mx=max3(a[i].a1,a[i].a2,a[i].a3);
            ans+=mx;
            if(a[i].a1==mx)
                d1.push_back(i);
            else if(a[i].a2==mx)
                d2.push_back(i);
            else
                d3.push_back(i);
        }
        sort(d1.begin(),d1.end(),cmp);
        sort(d2.begin(),d2.end(),cmp);
        sort(d3.begin(),d3.end(),cmp);
        if(d1.size()>n/2)
        {
            for(int i=0;d1.size()-n/2>i;i++)
            {
                int md=max(a[d1[i]].a2,a[d1[i]].a3);
                ans=ans-a[d1[i]].a1+md;
            }
        }
        else if(d2.size()>n/2)
        {
            for(int i=0;d2.size()-n/2>i;i++)
            {
                int md=max(a[d2[i]].a1,a[d2[i]].a3);
                ans=ans-a[d2[i]].a2+md;
            }
        }
        else if(d3.size()>n/2)
        {
            for(int i=0;d3.size()-n/2>i;i++)
            {
                int md=max(a[d3[i]].a2,a[d3[i]].a1);
                ans=ans-a[d3[i]].a3+md;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you

洛谷 UID: 678175
关注 @jqQt0220 谢谢喵

笑点解析：2h 才切 T1
*/