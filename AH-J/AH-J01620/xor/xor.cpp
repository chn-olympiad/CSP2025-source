#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005],m,h,cnt;
struct c{
    int l,r;
}f[10000005];
bool cmp(c x,c y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if((a[i]^a[j])==k){
                f[++m].l=j+1;
                f[m].r=i;
                //cout<<j+1<<" "<<i<<endl;
            }
        }
    }
    sort(f+1,f+m+1,cmp);
    for(int i=1;i<=m;i++){
        //cout<<f[i].l<<" "<<f[i].r<<endl;
        if(f[i].l>h) cnt++,h=f[i].r;
    }
    cout<<cnt;
    return 0;
}
