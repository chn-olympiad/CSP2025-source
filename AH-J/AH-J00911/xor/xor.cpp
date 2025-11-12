#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,cnt,ans,x;
int a[500005],sum[500005];
struct node{
    int l,r;
}b[500005];
bool cmp(node x,node y){
    if(x.r!=y.r)return x.r<y.r;
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[j]^sum[i-1])==k){
                b[++ans].l=i;
                b[ans].r=j;
                break;
            }
        }
    }
    sort(b+1,b+ans+1,cmp);
    for(int i=1;i<=ans;i++){
        if(b[i].l>x){
            cnt++;
            x=b[i].r;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
