#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],ans,sum;
struct node{
    int l,r;
}b[100020];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
        if(x==k){
            ans++;
            b[ans].l=i;
            b[ans].r=i;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            x^=a[j];
            if(x==k){
                ans++;
                b[ans].l=i;
                b[ans].r=j;
                break;
            }
        }
    }
    sort(b+1,b+ans+1,cmp);
    int lst=0;
    for(int i=1;i<=ans;i++){
        if(b[i].l>lst){
            lst=b[i].r;
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}
