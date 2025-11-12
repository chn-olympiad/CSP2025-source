#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int t;
int n;
LL ans=0;
struct node {
    int a,b,c;
} a[N];
int maxxx(int a,int b,int c) {
    return max(max(a,b),c);
}
bool cmp(node n1,node n2) {
    return maxxx(n1.a,n1.b,n1.c)>maxxx(n2.a,n2.b,n2.c);
}
vector<int> v;
int cnt[6];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--) {
        ans=0;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++) {
            int ma=-1,maxfrom=0;
            if(cnt[1]+1<=n/2) {
                if(a[i].a>=ma) {
                    if(a[i].a>ma) {
                        maxfrom=1;
                        ma=a[i].a;
                    } else {
                        if(cnt[1]<cnt[maxfrom]) {
                            maxfrom=1;
                        }
                    }
                }
            }
            if(cnt[2]+1<=n/2) {
                if(a[i].b>=ma) {
                    if(a[i].b>ma) {
                        maxfrom=2;
                        ma=a[i].b;
                    } else {
                        if(cnt[2]<cnt[maxfrom]) {
                            maxfrom=2;
                        }
                    }
                }
            }
            if(cnt[3]+1<=n/2) {
                if(a[i].c>=ma) {
                    if(a[i].c>ma) {
                        maxfrom=3;
                        ma=a[i].c;
                    } else {
                        if(cnt[3]<cnt[maxfrom]) {
                            maxfrom=3;
                        }
                    }
                }
            }
            cnt[maxfrom]++;
            ans+=ma;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
