#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
string a,b;
int addd=1000000;
struct node
{
    string a,b;
    int len,l,r,mid;
    int x,y;
}rep[510];
vector<int> movid[1000000];
bool check(int i,int j,int k,int l)
{
    if(rep[k].x-rep[k].y!=i-j)
        return false;
    if(rep[k].len>l)
        return false;
    if(rep[k].l>i)
        return false;
    if(rep[k].r>l-(i+1))
        return false;
    return true;
}
bool cmp(node a,node b)
{
    return a.len<b.len;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>rep[i].a>>rep[i].b;
        rep[i].len=rep[i].a.size();
        rep[i].x=rep[i].a.find('b');
        rep[i].y=rep[i].b.find('b');
        rep[i].l=rep[i].x;
        rep[i].r=rep[i].len-(rep[i].x+1);
    }
    sort(rep+1,rep+n+1,cmp);
    for(int i=1;i<=n;i++)
        movid[rep[i].x-rep[i].y+addd].push_back(i);
    while(q--)
    {
        cin>>a>>b;
        ans=0;
        if(a.size()!=b.size())
        {
            cout<<0;
            return 0;
        }
        int la=a.size();
        int x=a.find('b');
        int y=b.find('b');
        for(int i=0;i<movid[x-y+addd].size();i++)
        {
            int id=movid[x-y+addd][i];
            if(rep[id].len>la)
                break;
            if(check(x,y,id,la)==true)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
