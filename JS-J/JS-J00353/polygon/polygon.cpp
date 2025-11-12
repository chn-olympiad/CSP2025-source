#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int ans=0;
int h[25000011];
vector<int>b,d;
vector<int>c,e;
int a[5011];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    h[a[1]]=0;
    b.push_back(1);
    c.push_back(a[1]);
    for(int i=2;i<=n;i++)//a[i] -> max
    {
        d=b,e=c;
        int len=b.size();
        for(int j=0;j<len;j++)
        {
            int u=b[j],v=c[j];
            if(v>a[i])
            {
                ans+=u,ans%=MOD;
            }
            if(h[v+a[i]]==0) d.push_back(u),e.push_back(v+a[i]),h[v+a[i]]=d.size()-1;
            else d[h[v+a[i]]]+=u,d[h[v+a[i]]]%=MOD;
        }
        if(h[a[i]]==0) d.push_back(1),e.push_back(a[i]),h[a[i]]=d.size()-1;
        else d[h[a[i]]]+=1,d[h[a[i]]]%=MOD;
        b=d,c=e;
    }
    cout<<ans;
    return 0;
}
