#include<bits/stdc++.h>
using namespace std;
struct node{
    int s,t;
};
node b[500005];
bool cmp(node x,node y){
    return x.t<y.t;
}
int n,k,m,ans,rec;
int a[500005],s[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=a[i]^s[i-1];
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int q=s[i]^s[j];
            if(q==k){
                node t;
                t.s=i+1,t.t=j;
                b[++m]=t;
            }
        }
    }
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(b[i].s>rec){
            ans++;
            rec=b[i].t;
        }
    }
    printf("%d",ans);
    return 0;
}
