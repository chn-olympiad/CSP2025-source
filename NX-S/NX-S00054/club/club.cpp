#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
    int a,b,c;
};
int n,_max=0,ji=0,A,B;
Node ren[200000];
bool book[300000];
int dg(int yi,int er,int san,int shu)
{
    //cout<<yi<<" "<<er<<" "<<san<<" "<<shu<<endl;
    if(shu>n)
    {
        _max=max(ji,_max);
        return 0;
    }
    if(yi>0)
    {
        ji+=ren[shu].a;
        dg(yi-1,er,san,shu+1);
        ji-=ren[shu].a;
    }
    if(er>0&&A==1)
    {
        ji+=ren[shu].b;
        dg(yi,er-1,san,shu+1);
        ji-=ren[shu].b;
        //cout<<"11111111111111111111111111111111111111111111111111111111111111111111111111111";
    }
    if(san>0&&B==1)
    {
        ji+=ren[shu].c;
        dg(yi,er,san-1,shu+1);
        ji-=ren[shu].c;
    }
    return 0;
}
void work()
{
    cin>>n;
    int shu=n/2;
    A=0,B=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ren[i].a>>ren[i].b>>ren[i].c;
        if(ren[i].b!=0)A=1;
        if(ren[i].c!=0)B=1;
        //cout<<1;
    }
    //cout<<A<<" "<<B<<endl;
    dg(shu,shu,shu,1);
    cout<<_max<<endl;
    for(int i=1;i<=n;i++)
    {
        ren[i].a=0;
        ren[i].b=0;
        ren[i].c=0;
    }
    ji=0;
    _max=0;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)work();
    return 0;
}
