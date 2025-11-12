#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int cnt=0;
    int sum=0;
    int t=0;
    bool T=true;
    while(t<n)
    {
        if(T==false)
        {
            t++;
            sum=0;
        }
        for(int i=t;i<=n-1;i++)
        {
            if(i==t)
            {
                sum+=v[i];
            }
            else
            {
                if(sum==0||v[i]==0)
                {
                    sum+=v[i];
                    sum*=-1;
                }
                else
                {
                    sum+=v[i];
                }
            }
            if(sum==m)
            {
                cnt++;
                sum=0;
                t=i+1;
                continue;
            }
        }
        T=false;
    }
    cout<<cnt;
    return 0;
}
