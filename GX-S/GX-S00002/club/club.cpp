#include <bits/stdc++.h>
using namespace std;
int b=0,n;
int MAX(vector<int>c,vector<int>d,vector<int>e,int i,int k,int ni,int mi,int li)
{
    n=b/2;
    if(i==b)
    {
        return k;
    }
    if(ni > n)
    {
        for(int j=i;j<b;j++)
        {
            c[i]=-1;
        }
    }
    if(mi > n)
    {
        for(int j=i;j<b;j++)
        {
            d[i]=-1;
        }
    }
    if(li > n )
    {
        for(int j=i;j<b;j++)
        {
            e[i]=-1;
        }
    }
    return max(MAX(c,d,e,i+1,k+c[i],ni+1,mi,li),max(MAX(c,d,e,i+1,k+d[i],ni,mi+1,li),MAX(c,d,e,i+1,k+e[i],ni,mi,li+1)));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a,x;
    cin>>a;
    vector<int>m,n,l;
    vector<int>s;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        for(int j=0;j<b;j++)
        {
            cin>>x;
            m.push_back(x);
            cin>>x;
            n.push_back(x);
            cin>>x;
            l.push_back(x);
        }
        s.push_back(MAX(m,n,l,0,0,1,1,1));
        m.clear();
        n.clear();
        l.clear();
        b=0;
    }
    for(int x:s)
    {
        cout<<x<<endl;
    }
    return 0;
}
