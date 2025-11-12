#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct node{
    int l,r;
}e[N];
int a[N],sum[N];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int l=sum[j]^sum[i-1];
            if(l==k){
                e[++num]={i,j};
            }
        }
    }
    if(num==0){
        cout<<0<<endl;
        return 0;
    }
    sort(e+1,e+1+num,cmp);
    int o=1,cnt=1;
    for(int i=2;i<=num;i++){
        if(e[i].l<=e[o].r)continue;
        o=i;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
