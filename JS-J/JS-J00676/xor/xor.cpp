#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
struct qj{
    int l;
    int r;
}b[500005];
bool cmp(qj x,qj y){
    if(x.r==y.r)return x.l<y.l;
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        int cur=a[i];
        for(int j=i;j<=n;j++){
            if(i==j){
                if(a[i]==k){
                    cnt++;
                    b[cnt].l=i;
                    b[cnt].r=j;
                    break;
                }
            }
            else{
                cur=cur^a[j];
                if(cur==k){
                    cnt++;
                    b[cnt].l=i;
                    b[cnt].r=j;
                    break;
                }
            }

        }
    }
    sort(b+1,b+cnt+1,cmp);
    int ans=0,rr=b[1].r;
    for(int i=1;i<=cnt;i++){
        if(b[i].l>rr){
            ans++;
            rr=b[i].r;
        }
    }
    if(cnt){
        ans++;
    }
    printf("%d",ans);
    return 0;
}
