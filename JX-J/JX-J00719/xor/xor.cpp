#include <bits/stdc++.h>
using namespace std;
long long n,k,once,cnt=0,ans=1;
struct yihuo
{
    long long pre;
    long long en;
};
vector<long long> a;
yihuo b[500010];
bool cmp(yihuo s1,yihuo s2)
{
    if(s1.en<s2.en) return true;
    else return false;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&once);
        a.push_back(once);
    }
    for(int i=0;i<n;i++)
    {
        long long must=a[i];
        if(must==k)
        {
            b[cnt].pre=i+1;
            b[cnt].en=i+1;
            cnt++;
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            must^=a[j];
            if(must==k)
            {
                b[cnt].pre=i+1;
                b[cnt].en=j+1;
                cnt++;
                break;
            }
        }
    }
    if(cnt==0) {cout<<0;return 0;}
    sort(b,b+cnt-1,cmp);
    long long last=b[0].en;
    for(int i=1;i<n;i++)
    {
        if(b[i].pre>last)
        {
            ans++;
            last=b[i].en;
        }
    }
    printf("%lld",ans);
    return 0;
}
