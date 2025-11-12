#include<bits/stdc++.h>
using namespace std;
int tmp;
vector<int>vec;
vector<pair<int,int> >pi;
int seat[14][14];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=(n*m);++i)
    {
        int h;
        scanf("%d",&h);
        if(i==1) tmp=h;
        vec.push_back(h);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int cr=1,cc=1,cnt=0;
    bool flag=false,o=false;
    int tot=n*m;
    if(n==1&&m==1)
    {
        printf("1 1\n");
        return 0;
    }
    pi.push_back({1,1});
    while(cnt!=tot)
    {
        while(cr!=n)
        {
            ++cr,++cnt,pi.push_back({cr,cc});
        }
        ++cc,++cnt;
        pi.push_back({cr,cc});
        if(cnt==tot) break;
        while(cr!=1)
        {
            --cr,++cnt,pi.push_back({cr,cc});
        }
        ++cc,++cnt;
        pi.push_back({cr,cc});
    }
    for(int i=0;i<vec.size();++i)
    {
        if(vec[i]==tmp)
        {
            printf("%d %d\n",pi[i].second,pi[i].first);
            return 0;
        }
    }
    return 0;
}
