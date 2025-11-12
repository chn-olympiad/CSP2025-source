#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct node {
    int a,b,c,d;
}k[maxn];
bool cmp1(node x,node y) {
    return x.a>y.a;
}
bool cmp2(node x,node y) {
    return x.d>y.d;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        memset(k,0,sizeof(k));
        int n;
        cin>>n;
        bool flag1=true,flag2=true;
        for(int i=1;i<=n;i++) {
            cin>>k[i].a>>k[i].b>>k[i].c;
            if(k[i].b!=0 || k[i].c!=0) flag1=false;
            if(k[i].c!=0) flag2=false;
            k[i].d=k[i].a-k[i].b;
        }
        if(flag1) {
            sort(k+1,k+n+1,cmp1);
            ll sum=0;
            for(int i=1;i<=n/2;i++) sum+=k[i].a;
            cout<<sum<<"\n";
        } else if(flag2) {
            sort(k+1,k+n+1,cmp2);
            ll sum=0;
            for(int i=1;i<=n/2;i++) sum+=k[i].a;
            for(int i=n/2+1;i<=n;i++) sum+=k[i].b;
            cout<<sum<<"\n";
        }else {
            if(n==2) {
                int ans=max(k[1].a+k[2].b,max(k[1].a+k[2].c,max(k[1].b+k[2].a,max(k[1].b+k[2].c,max(k[1].c+k[2].a,k[1].c+k[2].b)))));
                cout<<ans<<"\n";
            } else {
                ll sum=0;
                for(int i=1;i<=n;i++) {
                    sum+=max(k[i].a,max(k[i].b,k[i].c));
                } cout<<sum<<"\n";
            }
        }
    }
    return 0;
}
