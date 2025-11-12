#include <bits/stdc++.h>

using namespace std;
const int N=1e5+1;


vector<int>f;
vector<int>cnt;
int n;
struct node{
    int s[4];
}tree[N];
bool flag(int i)
{
    if(cnt[i]<n/2)return true;
    return false;
}
int maxx(node b)
{
    if(b.s[1]>=b.s[2]&&b.s[1]>=b.s[3])return b.s[1];
    if(b.s[2]>=b.s[1]&&b.s[2]>=b.s[3])return b.s[2];
    return b.s[3];
}
bool cmp(node s1,node s2)
{
    return maxx(s1)>maxx(s2);

}


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long ans=0;
        cin>>n;

        for(int i=1;i<=n;i++){

                for(int j=1;j<=3;j++)cin>>tree[i].s[j];

        }


        cnt.resize(4,0);
        sort(tree+1,tree+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            int idx=1,idy=1;
            int maxx=-1,maxy=-1;
            for(int j=1;j<=3;j++)
            {
                if(tree[i].s[j]>maxx){
                    maxx=tree[i].s[j];
                    idx=j;
                }
            }

            //cout<<maxx<<" "<<maxy<<" "<<endl;
            if(cnt[idx]<=n/2-1){
                cnt[idx]++;
                ans+=maxx;
            }
            else {
                for(int j=1;j<=3;j++)
                {

                    if(tree[i].s[j]>maxy&&j!=idx){
                    idy=j;
                    maxy=tree[i].s[j];
                }
                }
                cnt[idy]++;
                ans+=maxy;
            }
        }
        cout<<ans<<endl;
    }

}
