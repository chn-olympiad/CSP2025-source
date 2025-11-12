#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k,cnt,ans;
struct Node{
    int l,r;
}p[N];
bool cmp(Node x,Node y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    int mx=0;
    for(int i=1;i<=n;i++) scanf("%d",a+i),mx=max(mx,a[i]);
    if(mx<k){
        printf("0");
        return 0;
    }
    else if(mx==1 && k==1){
        for(int i=1;i<=n;i++)
            if(a[i]==1) ++ans;
        printf("%d",ans);
        return 0;
    }
    int R=n,x;
    for(int i=1;i<=n;i++){
        x=0;
        if(i>R) R=n;
        for(int j=i;j<=R;j++){
            x^=a[j];
            if(x==k){
                p[++cnt].l=i,p[cnt].r=R=j;
                break;
            }
        }
    }
    sort(p+1,p+cnt+1,cmp);
    mx=0;
    for(int i=1;i<=cnt;i++){
        if(p[i].l>mx) mx=p[i].r,++ans;
    }
    printf("%d",ans);
    return 0;
}
