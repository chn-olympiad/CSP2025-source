#include <bits/stdc++.h>
#define int long long
using namespace std;
struct seg{
    int x,l,r;
}ls[500501],ls2[500501];
bool cmp(seg a,seg b){
    return a.x > b.x;
}
int t[5001],cnt=0,tot=0,c2=0;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt++;
            if (j==i){
                ls[cnt].x=t[j];
                ls[cnt].l=i;
                ls[cnt].r=j;
            }
            else{
                ls[cnt].x=(ls[cnt-1].x ^ t[j]);
                ls[cnt].l=i;
                ls[cnt].r=j;
            }
        }
    }
    sort(ls+1,ls+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if (ls[i].x == k){
            int flag=1;
            for(int j=1;j<=c2;j++){
                if (!(ls2[j].r < ls[i].l || ls2[j].l > ls[i].r)) {
                    flag=0;
                    break;
                }
            }
            if (flag){
                c2++;
                tot++;
                ls2[c2]=ls[i];
            }
        }
        if (ls[i].x < k){
            break;
        }
    }
    cout<<tot;
}
