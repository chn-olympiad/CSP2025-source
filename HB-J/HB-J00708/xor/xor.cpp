#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
struct direcion{
    int l,r;
};
direcion d[500005];
bool cmp(direcion x,direcion y){
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    int m=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]^b[i-1]==k){
                d[++m].l=i;
                d[m].r=j;
            }
        }
    }
    sort(d+1,d+m+1,cmp);
    int maxx=-1;
    for(int i=1;i<=m;i++){
        int sum=0,id=i;
        for(int j=i;j<=m;j++){
            if(d[j].l>d[id].r){
                sum++;
                id=j;
            }
        }
        if(sum>maxx)maxx=sum;
    }
    cout<<maxx;
    return 0;
}