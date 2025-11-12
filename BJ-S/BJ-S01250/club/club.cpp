#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int N,T;
struct Student
{
    int v[4];
}a[MAXN];
int Max(Student s)
{
    int mx=max(max(s.v[1],s.v[2]),s.v[3]);
    if(s.v[1]==mx) return 1;
    if(s.v[2]==mx) return 2;
    return 3;
}
int Diff(Student s)
{
    int mx=max(max(s.v[1],s.v[2]),s.v[3]);
    if(s.v[1]==mx) return s.v[1]-max(s.v[2],s.v[3]);
    if(s.v[2]==mx) return s.v[2]-max(s.v[1],s.v[3]);
    return s.v[3]-max(s.v[1],s.v[2]);
}
vector<int>vec[4];
vector<int>vd;
int ans=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        for(int i=1;i<=3;i++) vec[i].clear();
        ans=0;
        for(int i=1;i<=N;i++) 
        {
            scanf("%d %d %d",&a[i].v[1],&a[i].v[2],&a[i].v[3]);
            vec[Max(a[i])].push_back(i);
            ans+=a[i].v[Max(a[i])];
        }
        if(vec[1].size()<=N/2&&vec[2].size()<=N/2&&vec[3].size()<=N/2)
        {
            printf("%d\n",ans);
            continue;
        }
        int id=1;
        if(vec[2].size()>N/2) id=2;
        if(vec[3].size()>N/2) id=3;
        vd.clear();
        for(int i=0;i<vec[id].size();i++) 
        {
         //   Student aa=a[vec[id][i]];
          //  printf("%d %d %d %d\n",aa.v[1],aa.v[2],aa.v[3],Diff(aa));
            vd.push_back(Diff(a[vec[id][i]]));
        }
        sort(vd.begin(),vd.end());
       // for(int i:vd) printf("[%d]",i);
        int i=0,tot=vec[id].size();
        for(int i=0;i<vd.size();i++)
        {
            ans-=vd[i];
            tot--;
            if(tot==N/2) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}