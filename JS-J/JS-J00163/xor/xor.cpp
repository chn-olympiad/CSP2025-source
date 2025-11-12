#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int n,k,a[maxn],sum[maxn],tmp;
long long cnt;
struct node{
    int s,e;
}q[maxn];
bool cmp(node A,node B){
    if(A.e==B.e) return A.s > B.s;
    return A.e < B.e;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        sum[i] = (sum[i-1]^a[i]);
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            tmp = (sum[j]^sum[i-1]);
            if(tmp==k){
                node h;
                h.s = i;
                h.e = j;
                q[++cnt] = h;
            }
        }
    }
    sort(q+1,q+cnt+1,cmp);
    long long ans = 0,last = 0;;
    for(int i = 1;i <= cnt;i++){
        if(q[i].s>last){
            last = q[i].e;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
