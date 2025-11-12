#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
int n;
struct peo{
    int a[4];
}p[Maxn];
bool cmp(peo x,peo y)
{
    int X[4],Y[4];
    for(int i=1;i<=3;i++)
    {
        X[i]=x.a[i];
        Y[i]=y.a[i];
    }
    sort(X+1,X+1+3,greater<int>());
    sort(Y+1,Y+1+3,greater<int>());

    return X[1]+Y[2]>X[2]+Y[1];
}
struct seg{
    int v;
    int id;
};
bool cmps(seg x,seg y)
{
    return x.v>y.v;
}
int work()
{
    sort(p+1,p+1+n,cmp);
    int cnt[4];
    for(int i=1;i<=3;i++)
    {
        cnt[i]=0;
    }
    //
    //
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        seg s[4];
        s[1]=(seg){p[i].a[1],1};
        s[2]=(seg){p[i].a[2],2};
        s[3]=(seg){p[i].a[3],3};
        sort(s+1,s+1+3,cmps);
        int i1=s[1].id,i2=s[2].id,i3=s[3].id;
        //cout<<"id:"<<i<<":"<<s[1].v<<","<<s[2].v<<","<<s[3].v<<endl;
        if(s[1].v==s[2].v && s[2].v==s[3].v)
        {
            if(cnt[i1]<=cnt[i2] && cnt[i1]<=cnt[i3])
            {
                cnt[i1]++;
                ans+=s[1].v;
            }else if(cnt[i2]<=cnt[i1] && cnt[i2]<=cnt[i3]){
                cnt[i2]++;
                ans+=s[2].v;
            }else{
                cnt[i3]++;
                ans+=s[3].v;
            }
        }else if(s[1].v==s[2].v){
            if(cnt[i1]<=cnt[i2])
            {
                cnt[i1]++;
                ans+=s[1].v;
            }else{
                cnt[i2]++;
                ans+=s[2].v;
            }
        }else{
            if(cnt[i1]<(n/2))
            {
                cnt[i1]++;
                ans+=s[1].v;
            }else{
                cnt[i2]++;
                ans+=s[2].v;
            }
        }
    }
    return ans;
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&p[i].a[1],&p[i].a[2],&p[i].a[3]);
    }
    //cout<<"GOT"<<endl;
    printf("%d\n",work());
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}

