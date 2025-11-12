#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;
using ll = long long;
int n;
ll dp[500050];
struct node{
    int idx,val;
} tmp[500050];
bool cmp(node a,node b){
    if(a.val!=b.val)return a.val<b.val;
    else return a.idx<b.idx;
}
int sum[500050],last[500050],k;
il int getlast(int x,int idx){
    int lft = 0,rgt = n,ans = -1;
    while(lft<=rgt){
        int mid = (lft+rgt) >> 1;
        if(tmp[mid].val > x){
            rgt = mid-1;
        } else if(tmp[mid].val<x){
            lft = mid+1;
        } else{
            if(tmp[mid].idx>=idx) rgt = mid-1;
            else{
                lft = mid+1;
                ans = mid;
            }
        }
    }
    if(ans!=-1)return tmp[ans].idx;
    else return -1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++){
        scanf("%d",&sum[i]);
        sum[i] ^= sum[i-1];
        tmp[i].val = sum[i];
        tmp[i].idx = i;
    }
    sort(tmp+1,tmp+1+n,cmp);
    for(int i = 1;i<=n;i++){
        last[i] = getlast(sum[i]^k,i);
    }
    for(int i = 1;i<=n;i++){
        if(last[i]!=-1)dp[i] = max(dp[i-1],dp[last[i]]+1);
        else dp[i] = dp[i-1];
        //cerr << last[i] << ' ';
    }
    printf("%lld",dp[n]);
    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
