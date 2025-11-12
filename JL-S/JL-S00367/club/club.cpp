#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e5 + 10;
struct node{
    int a,b,c;
}a[N];
int n,t1,t2,t3;

namespace sub1{
    int dfs(int k,int p1,int p2,int p3,int ans){
        if(k==0) return ans;
        t1=0,t2=0,t3=0;
        if(p1<n/2) t1=dfs(k-1,p1+1,p2,p3,ans+a[k].a);
        if(p2<n/2) t2=dfs(k-1,p1,p2+1,p3,ans+a[k].b);
        if(p3<n/2) t3=dfs(k-1,p1,p2,p3+1,ans+a[k].c);
        return max(t1,max(t2,max(0LL,t3)));
    }
    void solve(){
        cout<<dfs(n,0LL,0LL,0LL,0LL)<<endl;
    }
}

namespace sub2{
    bool cmp(node x,node y) {
        return x.a>y.a;
    }
    void solve(){
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1;i<=n/2;i++) {
            ans+=a[i].a;
        }
        cout<<ans<<endl;
    }
}

namespace sub3{
    int dfs(int k,int p1,int p2,int ans){
        if(k==0) return ans;
        t1=0,t2=0;
        k--;
        if(p1<n/2) t1=dfs(k,p1+1,p2,ans+a[k].a);
        if(p2<n/2) t2=dfs(k,p1,p2+1,ans+a[k].b);
        return max(t1,max(0LL,t2));
    }
    void solve(){
        cout<<dfs(n,0LL,0LL,0LL)<<endl;
    }
}

namespace sub4{
    void solve(){
        int sum=0;
        int p1=0,p2=0,p3=0;
        for (int i=1;i<=n;i++) {
            if(a[i].a>a[i].b&&a[i].a>a[i].c){
                if(p1<n/2){
                    p1++;
                    sum+=a[i].a;
                } else {
                    if(a[i].b>a[i].c) {
                        if(p2<n/2) {
                            p2++;
                            sum+=a[i].b;
                        } else {
                            p3++;
                            sum+=a[i].c;
                        }
                    } else{
                        if(p3<n/2){
                            p3++;
                            sum+=a[i].c;
                        } else{
                            p2++;
                            sum+=a[i].b;
                        }
                    }
                }
            }
            if(a[i].b>a[i].a&&a[i].b>a[i].c){
                if(p2<n/2){
                    p2++;
                    sum+=a[i].b;
                } else {
                    if(a[i].a>a[i].c) {
                        if(p1<n/2) {
                            p1++;
                            sum+=a[i].a;
                        } else {
                            p3++;
                            sum+=a[i].c;
                        }
                    } else{
                        if(p3<n/2){
                            p3++;
                            sum+=a[i].c;
                        } else{
                            p1++;
                            sum+=a[i].a;
                        }
                    }
                }
            }
            if(a[i].c>a[i].b&&a[i].c>a[i].a){
                if(p3<n/2){
                    p3++;
                    sum+=a[i].c;
                } else {
                    if(a[i].b>a[i].a) {
                        if(p2<n/2) {
                            p2++;
                            sum+=a[i].b;
                        } else {
                            p1++;
                            sum+=a[i].a;
                        }
                    } else{
                        if(p1<n/2){
                            p1++;
                            sum+=a[i].a;
                        } else{
                            p2++;
                            sum+=a[i].b;
                        }
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int q;
    cin>>q;
    while(q--){
        cin >> n;
        bool ta=1,tb=1;
        for(int i=1;i<=n;i++) {
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].b) ta=0;
            if(a[i].c){
                ta=0;
                tb=0;
            }
        }
        if(ta) sub2::solve();
        else if(tb) sub3::solve();
        else sub4::solve();
    }
    return 0;
}