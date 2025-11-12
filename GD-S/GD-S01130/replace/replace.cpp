#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define file(x) (fin(x),fout(x),0)

int xxxx=file(replace);

const int maxn=2e5+5,maxm=5e6+5;

int n,q;
int cis[maxn];

string t1,t2,s1,s2;

unordered_map<ull,vector<int>>mp;

struct tire
{
    int tot=1,rt=1;
    int ch[maxm][26];
    vector<int>vec[maxm];
    inline void ins(int l,int r,int id)
    {
        int x=rt;
        for(int i=l;i<=r;i++)
        {
            if(ch[x][t1[i]-'a']==0) ch[x][t1[i]-'a']=++tot;
            x=ch[x][t1[i]-'a'];
        }
        vec[x].emplace_back(id);
    }
    inline int work(int l,int r,int flg)
    {
        int x=rt,ans=0;
        for(auto v:vec[x])
        {
            if(flg==1) cis[v]++;
            else if(flg==-1) cis[v]--;
            else if(flg==2) ans+=(cis[v]==2);
        }
        for(int i=l;i<=r;i++)
        {
            if(ch[x][s1[i]-'a']==0) break;
            x=ch[x][s1[i]-'a'];
            for(auto v:vec[x])
            {
                if(flg==1) cis[v]++;
                else if(flg==-1) cis[v]--;
                else if(flg==2) ans+=(cis[v]==2);
            }
        }
        return ans;
    }
}Pre,Sub;

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2;
        int l=0,r=t1.size()-1;
        for(;t1[l]==t2[l];l++);
        for(;t1[r]==t2[r];r--);
        Pre.ins(0,l-1,i);Sub.ins(r+1,t1.size()-1,i);
        ull sum1=0,sum2=0;
        for(int j=l;j<=r;j++)
            sum1=sum1*137+t1[j],
            sum2=sum2*137+t2[j];
        sum1=sum1*sum2;
        mp[sum1].emplace_back(i);
    }
    for(int i=1;i<=q;i++)
    {
        cin>>s1>>s2;
        int l=0,r=s1.size()-1;
        for(;s1[l]==s2[l];l++);
        for(;s1[r]==s2[r];r--);
        ull sum1=0,sum2=0;
        for(int j=l;j<=r;j++)
            sum1=sum1*137+s1[j],
            sum2=sum2*137+s2[j];
        for(int j=l;j<=r;j++) sum1*=137;
        sum1=sum1*sum2;
        for(auto v:mp[sum1]) cis[v]++;
        Pre.work(0,l-1,1);
        printf("%d\n",Sub.work(r+1,s1.size()-1,2));
        Pre.work(0,l-1,-1);
        for(auto v:mp[sum1]) cis[v]--;
    }
}