#include<bits/stdc++.h>
using namespace std;
struct student{
    int id;
    int f[4];
    student()
    {
        id=0;
        for(int i=1;i<=3;++i) f[i]=0;
    }
};
vector<student>vec;
bool c1(student a,student b)
{
    return a.f[1]>b.f[1];
}
bool c2(student a,student b)
{
    return a.f[2]>b.f[2];
}
bool c3(student a,student b)
{
    return a.f[3]>b.f[3];
}
long long func(int n,int g)
{
    long long res=0;
    switch(g)
    {
        case 1:sort(vec.begin(),vec.end(),c1);break;
        case 2:sort(vec.begin(),vec.end(),c2);break;
        case 3:sort(vec.begin(),vec.end(),c3);break;
    }
    if(g==1)
    {
        long long cnt=0;
        for(int i=0;i<=(n/2)-1;++i) cnt+=vec[i].f[1];
        for(int i=n/2;i<vec.size();++i) cnt+=max(vec[i].f[2],vec[i].f[3]);
        res=max(res,cnt);
    }
    else if(g==2)
    {
        long long cnt=0;
        for(int i=0;i<=(n/2)-1;++i) cnt+=vec[i].f[2];
        for(int i=n/2;i<vec.size();++i) cnt+=max(vec[i].f[2],vec[i].f[3]);
        res=max(res,cnt);
    }
    else
    {
        long long cnt=0;
        for(int i=0;i<=(n/2)-1;++i) cnt+=vec[i].f[3];
        for(int i=n/2;i<vec.size();++i) cnt+=max(vec[i].f[1],vec[i].f[2]);
        res=max(res,cnt);
    }
    return res;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;++j)
        {
            student s;
            scanf("%d%d%d",&s.f[1],&s.f[2],&s.f[3]);
            s.id=j;
            vec.push_back(s);
        }
        long long fin=max(max(func(n,1),func(n,2)),func(n,3));
        printf("%lld\n",fin);
        vec.clear();
    }
    return 0;
}
