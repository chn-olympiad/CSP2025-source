#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2*N;
int w[M],e[M],ne[M],h[N],idx;
void add(int a,int b,int c)
{
    e[idx]=a,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int ans=0;
    for(int i=0;i<k;i++)
    {
        int a,cnt=0,re=0;
        cin>>a;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            cnt+=w[h[a]];
            re+=x;
        }
        ans+=min(re+a,cnt);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
