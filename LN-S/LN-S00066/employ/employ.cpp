#include<bits/stdc++.h>
#define Std_Maker lhm
#define ll long long
using namespace std;
const int mod=998244353,N=1001;
ll n,m,cnt,p[N],ans,res,d[N];
char ch;
struct lhm
{
    ll c,num;
}stu[N],te[N];
bool cmp(lhm a,lhm b)
{
    return a.num<b.num;
}
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='0') d[i]=0;
        else d[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>stu[i].c;
        te[i].c=stu[i].c;
    }
    for(int i=1;i<=n;i++) p[i]=i;
    do
    {
        cnt=0,res=0;
        for(int i=1;i<=n;i++) stu[i].c=te[i].c;
        for(int i=1;i<=n;i++) stu[i].num=p[i];
        sort(stu+1,stu+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(cnt>=stu[i].c or d[i]==0)
            {
                cnt++;
                continue;
            }
            else if(d[i]==1) res++;
        }
        if(res>=m) ans++,ans%=mod;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans%mod;
    return 0;
}
//1h49min 8pts?
