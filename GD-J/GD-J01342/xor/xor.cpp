#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,ans;
int c[5*100002];
struct node{
    int l,r;
}a[5*100002];
int ct=0;
bool cmp(node a,node b){
    return a.l<b.l;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }for(int start=1;start<=n;start++){
        int sum=0;
        for(int i=start;i<=n;i++){
            sum^=c[i];
            if(sum==m){
                a[++ct].l=start;
                a[ct].r=i;
                break;
            }
        }
    }
    sort(a+1,a+ct+1,cmp);
    int s=0;
    for(int i=1;i<=ct;i++){
        if(a[i].l>s){
            s=a[i].r;
            ans++;
        }
    }cout<<ans;
    return 0;
}
