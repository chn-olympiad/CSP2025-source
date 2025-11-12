#include<bits/stdc++.h>
using namespace std;
int t;
struct person {
    int val[4];
    int maxn,max2;
};
bool cmp(person x,person y) {
    if(x.maxn==y.maxn) {
        return x.val[x.maxn]>y.val[y.maxn];
    } else {
        return x.maxn<y.maxn;
    }
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--) {
        int n;
        person a[100010];
        cin>>n;
        for(int i=1;i<=n;i++) {
            int x,y,z;
            cin>>x>>y>>z;
            a[i].val[1]=x;
            a[i].val[2]=y;
            a[i].val[3]=z;
            int mmax=-1,mmaxn=0;
            for(int j=1;j<=3;j++) {
                if(a[i].val[j]>mmax) {
                    mmax=a[i].val[j];
                    a[i].max2=mmaxn;
                    mmaxn=j;
                }
            }
            a[i].maxn=mmaxn;
        }
        sort(a+1,a+n+1,cmp);
        int cnt[4]={0,0,0,0},ans=0;
        for(int i=1;i<=n;i++) {
            if(cnt[a[i].maxn]<n/2) {
                cnt[a[i].maxn]++;
                ans+=a[i].val[a[i].maxn];
            } else {
                cnt[a[i].max2]++;
                ans+=a[i].val[a[i].max2];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
