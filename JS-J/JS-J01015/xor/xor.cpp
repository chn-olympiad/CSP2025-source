#include<bits/stdc++.h>
using namespace std;
int a[500001];
struct node{
    int l,r;
}b[100001];
bool cmp(node x,node y){
    return x.l<y.l;
}
int tot=0,maxn=0;
void work(int dep,int d,int sum){
    if(dep>tot){
        maxn=max(maxn,sum);
        return ;
    }
    work(dep+1,d,sum);
    if(d<b[dep].l)work(dep+1,b[dep].r,sum+1);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,tot1=0,tot0=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)tot1++;
        if(a[i]==0)tot0++;
    }
    if(k==1){
        cout<<tot1;
        return 0;
    }
    if(k==0){
        cout<<tot0+tot1/2;
        return 0;
    }
    tot=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sum=a[i];
            for(int t=i+1;t<=j;t++){
                sum=(sum^a[t]);
            }
            if(sum==k){
                b[++tot].l=i;b[tot].r=j;
                break;
            }
        }
    }
    sort(b+1,b+1+tot,cmp);
    work(1,0,0);
    cout<<maxn;
    return 0;
}
