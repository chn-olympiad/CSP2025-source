#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}a[300000];
int cnt=0,x[500000],qzs[500000];
bool cmp(const node &x,const node &y){
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        qzs[i]=(qzs[i-1]^x[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((qzs[j]^qzs[i-1])==k||(i==j&&x[i]==k)){
                a[++cnt].l=i;
                a[cnt].r=j;
            }
        }
    }
    sort(a+1,a+cnt+1,cmp);
    int cnt=1,maxn=-1;
    for(int i=1;i<=cnt;i++){
            int rp=a[i].r;
        for(int j=i+1;j<=cnt;j++){
            if(a[j].l>rp){
                cnt++;
                rp=a[j].r;
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}

