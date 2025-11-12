#include <bits/stdc++.h>
using namespace std;
#define ppi pair<pair<int,int>,int>
#define fs first
#define sc second
const int N=1e5+10;
int t,n;
bool ok[N];
struct node
{
    int a,b,c;
}a[N];
vector<ppi> v1,v2,v3;
vector<int> c1,c2,c3;
bool cmp(ppi a,ppi b)
{
    if(a.fs.fs!=b.fs.fs) return a.fs.fs>b.fs.fs;
    return a.sc<b.sc;
}
long long tot;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        v1.clear();
        v2.clear();
        v3.clear();
        c1.clear();
        c2.clear();
        c3.clear();
        tot=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            v1.push_back({{a[i].a,i},a[i].b+a[i].c});
            v2.push_back({{a[i].b,i},a[i].a+a[i].c});
            v3.push_back({{a[i].c,i},a[i].a+a[i].b});
            ok[i]=0;
        }
        sort(v1.begin(),v1.end(),cmp);
        sort(v2.begin(),v2.end(),cmp);
        sort(v3.begin(),v3.end(),cmp);

        ok[v1.back().fs.sc]=1;
        c1.push_back(v1.back().fs.sc);
        tot+=v1.back().sc;
        v1.pop_back();

        if(ok[v2.back().fs.sc]) v2.pop_back();
        ok[v2.back().fs.sc]=1;
        c2.push_back(v2.back().fs.sc);
        tot+=v2.back().sc;
        v2.pop_back();

        if(ok[v3.back().fs.sc]) v3.pop_back();
        ok[v3.back().fs.sc]=1;
        c2.push_back(v3.back().fs.sc);
        tot+=v3.back().sc;
        v3.pop_back();

        for(int i=1,maxn,pl;i<=n;i++)
        {
            if(ok[i]) continue;
            maxn=-1,pl=0;
            if(a[i].a>maxn) maxn=a[i].a,pl=1;
            if(a[i].b>maxn) maxn=a[i].b,pl=2;
            if(a[i].c>maxn) maxn=a[i].c,pl=3;
            bool fl=1;
            switch (pl)
            {
                case 1:
                    if(c1.size()>=n/2)
                    {
                        a[i].a=-1;
                        break;
                    }
                    else
                        c1.push_back(i),tot+=maxn,fl=0;
                case 2:
                    if(c2.size()>=n/2)
                    {
                        a[i].b=-1;
                        break;
                    }
                    else
                        c2.push_back(i),tot+=maxn,fl=0;
                case 3:
                    if(c3.size()>=n/2)
                    {
                        a[i].c=-1;
                        break;
                    }
                    else
                        c3.push_back(i),tot+=maxn,fl=0;
            }
            if(fl)
            {
                maxn=-1,pl=0;
                if(a[i].a>maxn) maxn=a[i].a,pl=1;
                if(a[i].b>maxn) maxn=a[i].b,pl=2;
                if(a[i].c>maxn) maxn=a[i].c,pl=3;
                if(a[i].c>maxn) maxn=a[i].c,pl=3;
                bool fl=1;
                switch (pl)
                {
                    case 1:
                        if(c1.size()>=n/2)
                        {
                            a[i].a=-1;
                            break;
                        }
                        else
                            c1.push_back(i),tot+=maxn,fl=0;
                    case 2:
                        if(c2.size()>=n/2)
                        {
                            a[i].b=-1;
                            break;
                        }
                        else
                            c2.push_back(i),tot+=maxn,fl=0;
                    case 3:
                        if(c3.size()>=n/2)
                        {
                            a[i].c=-1;
                            break;
                        }
                        else
                            c3.push_back(i),tot+=maxn,fl=0;
                }
            }
        }
        cout<<tot<<"\n";
    }
    return 0;
}
