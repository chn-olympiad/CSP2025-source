#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int n;

struct node
{
    int a,b,c;
    int id;
}s[MAXN];

bool cmp(node a,node b)
{
    return a.a>b.a;
}

void count_a()
{
    sort(s,s+n,cmp);
    long long ans=0;
    for(int i=0;i<n/2;i++)
        ans+=s[i].a;
    cout<<ans<<'\n';
}

int count(int b1,int b2,int b3,int w,int sum)
{
    int man[]={b1,b2,b3};
    if(w>=n)
        return sum;
    int ans=-1;
    for(int i=0;i<3;i++)
    {
        if(man[i]<n/2)
        {
            man[i]++;
            if(i==0) sum+=s[w].a;
            else if(i==1) sum+=s[w].b;
            else sum+=s[w].c;
            int tmp=count(man[0],man[1],man[2],w+1,sum);
            ans=max(ans,tmp);
            if(i==0) sum-=s[w].a;
            else if(i==1) sum-=s[w].b;
            else sum-=s[w].c;
            man[i]--;
        }
    }
    return ans;
}

void find_ans()
{
    cin>>n;
    bool is_a=true;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].a>>s[i].b>>s[i].c;
        s[i].id=i;
        if(s[i].b!=0||s[i].c!=0)
            is_a=false;
    }
    if(is_a)
        count_a();
    else
        cout<<count(0,0,0,0,0)<<'\n';
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        find_ans();
    }
    return 0;
}