#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn][3],cnt[3],m[maxn];
vector<int> s;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cnt[0]=cnt[1]=cnt[2]=0;
        s.clear();
        int n;
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            int w=0;
            if(a[i][0]>=max(a[i][1],a[i][2]))w=0;
            if(a[i][1]>=max(a[i][0],a[i][2]))w=1;
            if(a[i][2]>=max(a[i][1],a[i][0]))w=2;
            ans+=a[i][w];
            m[i]=w;
            cnt[w]++;
        }
        int k=3;
        if(cnt[0]>n/2)k=0;
        if(cnt[1]>n/2)k=1;
        if(cnt[2]>n/2)k=2;
        if(k==3)
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            if(m[i]==k)
            {
                int p=-1e9;
                for(int j=0;j<3;++j)
                {
                    if(j!=k)p=max(p,a[i][j]);
                }
                s.push_back(p-a[i][k]);
            }
        }
        sort(s.begin(),s.end());
        for(int i=1;i<=s.size()-n/2;++i)
        {
            ans+=s[s.size()-i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
