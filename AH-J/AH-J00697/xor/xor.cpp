#include<bits/stdc++.h>
using namespace std;
int a[500005];
int pre[500005];
struct node{
    int l,r;
}x[500005];
bool cmp(node p1,node p2){
    if(p1.r!=p2.r){
        return p1.r<p2.r;
    }
    return p1.l<p2.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]^a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((pre[j]^pre[i-1])==k){
                x[++cnt].l=i;
                x[cnt].r=j;
            }
        }
    }
    sort(x+1,x+cnt+1,cmp);
    int ans=1;
    int nr=x[1].r;
    for(int i=2;i<=cnt;i++){
        if(x[i].l>nr){
            nr=x[i].r;
            ans++;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
