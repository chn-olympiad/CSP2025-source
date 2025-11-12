#include<bits/stdc++.h>
const int maxn=1e5+5;
using namespace std;
int n,t,mod;
struct node{
    int d1,d2,d3;
    int c1,c2,c3;
}v[maxn];
bool cmp(node x, node y)
{
    if(x.c1!=y.c1)
    {
        return x.c1>y.c1;
    }
    else if(x.c2!=y.c2)
    {
        return x.c2<x.c2;
    }
    else
    {
        return x.c3<y.c3;
    }
}
stack <node> s1,s2,s3;
int b[maxn][5];
int a[maxn][5];
long long ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
    n=0,ans=0;
    cin>>n;
    if(n==2)
    {
        long long a,b,c,d,e,f;
        long long sum1,sum2,sum3;
        cin>>a>>b>>c>>d>>e>>f;
        ans=max({a+e,a+f,b+d,b+f,c+d,c+e});
        cout<<ans;
    }
    else
    {
    mod=n/2;
    for(int i=1;i<=n;i++)
    {
        //int sum=0;
        //v[i].id=i;
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        b[i][1]=1,b[i][2]=2,b[i][3]=3;
        if(a[i][2]<a[i][3])
        {
            swap(a[i][2],a[i][3]);
            swap(b[i][2],b[i][3]);
        }
        if(a[i][1]<a[i][2])
        {
            swap(a[i][1],a[i][2]);
            swap(b[i][1],b[i][2]);
        }
        if(a[i][2]<a[i][3])
        {
            swap(a[i][2],a[i][3]);
            swap(b[i][2],b[i][3]);
        }
        v[i].c1=a[i][1],v[i].c2=a[i][2],v[i].c3=a[i][3];
        v[i].d1=b[i][1],v[i].d2=b[i][2],v[i].d3=b[i][3];
    }
    sort(v+1,v+1+n,cmp);
    int cnt1=0,cnt2=0,cnt3=0,f=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].d1==1)
        {
            cnt1++;
            s1.push(v[i]);
            ans+=v[i].c1;
        }
        else if(v[i].d1==2)
        {
            cnt2++;
            s2.push(v[i]);
            ans+=v[i].c1;
        }
        else{
            cnt3++;
            s3.push(v[i]);
            ans+=v[i].c1;
        }
    }
    while(cnt1>mod)
    {
        cnt1--;
        ans-=s1.top().c1;
        if(s1.top().d2==2)
        {
            cnt2++;
            s2.push(s1.top());
            ans+=s1.top().c2;
            f=1;
        }
        else{
            cnt3++;
            s3.push(s1.top());
            ans+=s1.top().c2;
        }
        s1.pop();
    }
    while(cnt2>mod)
    {
        cnt2--;
        if(f==0)
        {
            ans-=s2.top().c1;
            //cnt3++;
            //s3.push(s2.top());
            ans+=s2.top().c2;
            s2.pop();
        }
        else if(f==1)
        {
            ans-=s2.top().c2;
            //cnt3++;
            //s3.push(s2.top());
            ans+=s2.top().c3;
            s2.pop();
        }
    }
    cout<<ans<<'\n';
    }
    }
}
