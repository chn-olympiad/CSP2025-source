#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],top;
struct node{
    int l,r;
}q[500010];
inline bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]^a[i];
    }
    //cout<<k<<"\n";
    int ml=n;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=ml;j++){
            int kk=b[j]^b[i-1];
            if(kk==k){
                //cout<<kk<<" "<<k<<"\n";
                q[++top]={i,j};
                ml=j;
                break;
            }
        }
    }
    sort(q+1,q+top+1,cmp);
    int res=0,now_r;
    for(int i=1;i<=n;){
        now_r=q[i++].r;
        res++;
        while(q[i].l<=now_r&&i<=n)i++;
    }
    printf("%d",res);
    return 0;
}
