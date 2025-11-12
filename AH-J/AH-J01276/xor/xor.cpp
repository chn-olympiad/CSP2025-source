#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int s,e;
}b[500005];
int n,k,a[500005],sum[500005],cnt,c;
bool cmp(node x,node y){
    if(x.e!=y.e) return x.e<y.e;
    return x.s>y.s;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>a[1];
    sum[1]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]^a[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((sum[j]^sum[i])==k){
                //cnt++;
                //cout<<i+1<<" "<<j<<endl;
                b[++c].s=i+1;
                b[c].e=j;
            }
        }
    }
    sort(b+1,b+c+1,cmp);
    cnt++;
    int pos=b[1].e;
    //cout<<b[1].s<<" "<<b[1].e<<endl;
    for(int i=2;i<=c;i++){
        if(b[i].s>pos){
            pos=b[i].e;
            //cout<<b[i].s<<" "<<b[i].e<<endl;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
