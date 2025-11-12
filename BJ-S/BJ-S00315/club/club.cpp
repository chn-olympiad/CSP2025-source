#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t,n;
struct nb
{
    int m[4],c;
    friend bool operator<(nb n1,nb n2)
    {return n1.c<n2.c;}
}a[100005];
long long ans;
vector<nb> st[4];
int main(void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ans=0;
        st[1]=st[2]=st[3]=vector<nb>();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d%d",&a[i].m[1],&a[i].m[2],&a[i].m[3]);
            for(short f=1;f<=3;++f)
                if(a[i].m[f]>=a[i].m[1]&&a[i].m[f]>=a[i].m[2]&&a[i].m[f]>=a[i].m[3])
                {
                    ans+=a[i].m[f];
                    a[i].c=a[i].m[f]-max(a[i].m[f==3?1:f+1],a[i].m[f==1?3:(f+2)%3]);
                    st[f].push_back(a[i]);
                    break;
                }
        }
        for(int f=1;f<=3;++f)
        {
            int sz=st[f].size();
            if(sz>n/2)
            {
                sort(st[f].begin(),st[f].end());
                for(int i=0;i<sz-n/2;++i)ans-=st[f][i].c;
                break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
