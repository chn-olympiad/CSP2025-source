#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long a,k;
vector<long long> sum;
struct node{
    int l,r;
};
int m[1505][20005];
node v[1000005];
int dfs(int i,int pos){
    if(m[i][pos]!=-1){
        return m[i][pos];
    }
    if(i==n+1)return 0;
    if(v[i].l<=pos)return m[i][pos]=dfs(i+1,pos);
    return m[i][pos]=max(dfs(i+1,pos),dfs(i+1,v[i].r)+1);
}
bool cmp(node x,node y){
    if(x.l!=y.l)return x.l<y.l;
    return x.r<y.r;
}
int main(){
    memset(m,-1,sizeof(m));
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    sum.push_back(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        sum.push_back(sum[i-1]^a);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                v[++cnt]={i,j};
                break;
            }
        }
    }
    sort(v+1,v+1+n,cmp);
    cout<<dfs(1,0);
    return 0;
}
