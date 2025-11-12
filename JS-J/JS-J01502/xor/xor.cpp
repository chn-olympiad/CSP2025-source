#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,k,a[N],x[N],dig,vis[1000005],ans,flag;
struct node{
    int l;
    int r;
    int s;
}c[1000005];
bool cmp(node x,node y){
    return x.s<y.s;
}
int main(){
    //xor same->0 different -> 1
    //  tan!
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){
                    long long xo;
                    xo=a[i];
            for(int k=i+1;k<=j;k++){
                xo=(xo^a[k]);
            }
            if(xo==k){
                c[++dig]={i,j,j-i+1};
            }
        }
    }
    sort(c+1,c+1+dig,cmp);
    for(int i=1;i<=dig;i++){
            flag=0;
            long long st=c[i].l,ed=c[i].r;
        for(int j=st;j<=ed;j++){
            if(vis[j]){
                flag=1;
                break;
            }
        }
        if(flag)continue;
        //cout<<st<<' '<<ed<<endl;
        for(int p=st;p<=ed;p++){
            vis[p]=1;
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
