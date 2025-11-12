#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 500005
using namespace std;
struct node{
    int l,r;
}t[MAXN];
bool cmp(node p,node q){
    if(p.r!=q.r) return p.r<q.r;
    return p.l<q.l;
}
int n,k,a[MAXN],sum[MAXN],cnt,ans=1,pos;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        sum[i]=(sum[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                ++cnt;
                t[cnt].l=i;
                t[cnt].r=j;
                break;
            }
        }
    }
    sort(t+1,t+cnt+1,cmp);
    pos=t[1].r;
    for(int i=2;i<=cnt;i++){
        if(t[i].l>pos){
            ans++;
            pos=t[i].r;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
