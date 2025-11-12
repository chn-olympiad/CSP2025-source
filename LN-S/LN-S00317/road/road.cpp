#include <bits/stdc++.h>
using namespace std;
long long h[10010];
long long ind[100010];
long long g[100010][10];
long long cc[100010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    long long cnt=0;
    for(int i=0;i<m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        h[a]++;
        h[b]++;
        ind[i]=i;
        g[i][0]=a;
        g[i][1]=b;
        g[i][2]=c;
        cc[i]=c;
        cnt+=c;
    }
    for(int i=0;i<k;i++)
    {
        int d;
        cin>>d;
        for(int j=0;j<n;j++)
        {
            int l;
            cin>>l;
        }
    }
    sort(ind,ind+m,[&](int i,int j)->bool{
        return cc[i]>cc[j];
    });
    //for(int i=0;i<n;i++)
    //{
        //  cout<<h[i]<<endl;
    //}
    for(int i=0;i<m;i++)
    {
        if(h[g[ind[i]][0]]>=2 and h[g[ind[i]][1]]>=2)
        {
            cnt-=cc[ind[i]];
            h[g[ind[i]][0]]--;
            h[g[ind[i]][1]]--;
            //cout<<g[ind[i]][0]<<" "<<g[ind[i]][1]<<endl;
            //cout<<cnt<<endl;
        }
    }
    if(k==0)
    {
        cout<<cnt;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
