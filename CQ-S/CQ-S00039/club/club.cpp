#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a1,a2,a3,x;
};
node a[100001];
vector<node>v[4];
bool cmp(node xx,node yy)
{
    return xx.x<yy.x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        v[1].clear();
        v[2].clear();
        v[3].clear();
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            int maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
            if(maxn==a[i].a1)v[1].push_back(a[i]);
            else if(maxn==a[i].a2)v[2].push_back(a[i]);
            else v[3].push_back(a[i]);
            sum+=maxn;
        }
        if(v[1].size()>n/2)
        {
            for(int i=0;i<v[1].size();i++)
            {
                if(v[1][i].a2>v[1][i].a3)v[1][i].x=v[1][i].a1-v[1][i].a2;
                else v[1][i].x=v[1][i].a1-v[1][i].a3;
            }
            sort(v[1].begin(),v[1].end(),cmp);
            int sum2=0;
            for(int i=0;i<v[1].size()-n/2;i++)
            {
                sum2+=v[1][i].x;
            }
            cout<<sum-sum2<<endl;
        }
        else if(v[2].size()>n/2)
        {
            for(int i=0;i<v[2].size();i++)
            {
                if(v[2][i].a3>v[2][i].a1)v[2][i].x=v[2][i].a2-v[2][i].a3;
                else v[2][i].x=v[2][i].a2-v[2][i].a1;
            }
            sort(v[2].begin(),v[2].end(),cmp);
            int sum2=0;
            for(int i=0;i<v[2].size()-n/2;i++)
            {
                sum2+=v[2][i].x;
            }
            cout<<sum-sum2<<endl;
        }
        else if(v[3].size()>n/2)
        {
            for(int i=0;i<v[3].size();i++)
            {
                if(v[3][i].a1>v[3][i].a2)v[3][i].x=v[3][i].a3-v[3][i].a1;
                else v[3][i].x=v[3][i].a3-v[3][i].a2;
            }
            sort(v[3].begin(),v[3].end(),cmp);
            int sum2=0;
            for(int i=0;i<v[3].size()-n/2;i++)
            {
                sum2+=v[3][i].x;
            }
            cout<<sum-sum2<<endl;
        }
        else
        {
            cout<<sum<<endl;
        }
    }
    return 0;
}
