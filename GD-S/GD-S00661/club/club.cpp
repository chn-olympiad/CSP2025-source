#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct student
{
    int k,a[3],b[3],id;
    bool operator>(const student t)const
    {
        return a[b[k]]-a[b[k+1]]>t.a[t.b[t.k]]-t.a[t.b[t.k+1]];
    }
}s[100005];
priority_queue<student,vector<student>,greater<student> >q[3],Nul;
void join(student x)
{
    int d=x.b[x.k];
    q[d].push(x),ans+=x.a[d];
    if(q[d].size()>n/2)
    {
        student v=q[d].top();
        q[d].pop(),ans-=v.a[v.b[v.k]];
        v.k++;
        join(v);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--&&cin>>n)
    {
        q[0]=q[1]=q[2]=Nul;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)cin>>s[i].a[j];
            iota(s[i].b,s[i].b+3,0);
            sort(s[i].b,s[i].b+3,[i](int x,int y){return s[i].a[x]>s[i].a[y];});
            s[i].k=0,s[i].id=i;
            join(s[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
g++ club.cpp -o club
club.exe

// freopen("club.in","r",stdin);
// freopen("club.out","w",stdout);
// freopen("club.in","r",stdin);
// freopen("club.out","w",stdout);
// freopen("club.in","r",stdin);
// freopen("club.out","w",stdout);
// freopen("club.in","r",stdin);
// freopen("club.out","w",stdout);
// freopen("club.in","r",stdin);
// freopen("club.out","w",stdout);
*/