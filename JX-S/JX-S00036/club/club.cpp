#include<bits/stdc++.h>
using namespace std;

int MAX_N=1e5+10;
struct prefer{
    int group,per;
};

struct student{
prefer a1,a2,a3;
};

bool cmp1(prefer a,prefer b)
{
    return a.per>b.per;
}

bool cmp2(student a,student b)
{
    return a.a1.per>b.a1.per;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<student> stu;

        for(int i=1;i<=n;i++)
        {
            vector<prefer> ps;
            for(int j=0;j<3;j++)
            {
                int a;cin>>a;
                prefer temp1={j+1,a};
                ps.push_back(temp1);
            }
            sort(ps.begin(),ps.end(),cmp1);
            student temp2={ps[0],ps[1],ps[2]};
            stu.push_back(temp2);
        }
        sort(stu.begin(),stu.end(),cmp2);

        int g[4]={0,0,0,0},maxg=n/2,sump=0;
        for(int i=0;i<stu.size();i++)
        {
            if(g[stu[i].a1.group]<maxg)
            {
                sump+=stu[i].a1.per;
                g[stu[i].a1.group]++;
            }else if(g[stu[i].a2.group]<maxg)
            {
                sump+=stu[i].a2.per;
                g[stu[i].a2.group]++;
            }else
            {
                sump+=stu[i].a3.per;
                g[stu[i].a3.group]++;
            }
        }
        cout<<sump<<endl;
    }
    return 0;
}
