#include<bits/stdc++.h>
using namespace std;
struct node{
    int started,ended;
};
int a[500005];
node b[500005];
int n,k,bs=0;
bool cmp(node x,node y){
    return x.started<y.started;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=i;j<=n;j++){
            tmp^=a[j];
            if(tmp==k){
                b[++bs].started=i;
                b[bs].ended=j;
                break;
            }
        }
    }
    sort(b+1,b+bs+1,cmp);
    int ans=0,ttmp1=0;
    for(int i=1;i<=bs;i++){
        if(b[i].started>ttmp1){
            ans++;
            ttmp1=b[i].ended;
        }
        else if(b[i].ended<ttmp1){
            ttmp1=b[i].ended;
        }
    }
    printf("%d",ans);
}
