#include<bits/stdc++.h>
#define int long long
using namespace std;
struct c{
    int l,r;
}s[1000001];
int a[500005],f[1001];
int n,k,cnt,res;
//int res(int L,int R,int cnt2,int p){
    //for(;L<=n&&cnt2<=cnt;){
       // while(s[cnt2].r>=R)
   // }
//}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int p=f[i-1]^f[j];
            if(p==k){
                s[++cnt].l=i;
                s[cnt].r=j;
                break;
            }
        }
    }
    if(s[1].l){
        res++;
    }
   // for(int i=1;i<=cnt;i++){
     //   cout<<s[i].l<<' '<<s[i].r<<endl;
    //}
    int L=s[1].l,R=s[1].r;
    for(int i=2;i<=cnt;i++){
        if(s[i].r<=R){
            L=s[i].l;
            R=s[i].r;
        }
        else if(s[i].r>R&&s[i].l<R){
            L=s[i].l;
            R=s[i].r;
        }
        else if(s[i].l>=R){
            L=s[i].l;
            R=s[i].r;
            res++;
        }
    }
    cout<<res;
    return 0;
}
