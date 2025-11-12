#include<bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
}s[1000005];
int n,k;
bool cmp(node x,node y){
    if(x.r!=y.r){
        return x.r<y.r;
    }
    return x.l>y.l;
}
int a[1005],x[1005][1005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=2){
        cin>>a[1]>>a[2];
        if(a[1]^a[2]==k||a[1]==k||a[2]==k){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(n<=1000){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                x[i][j]=a[i];
                for(int k=i+1;k<=j;k++){
                    x[i][j]^=a[k];
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(x[i][j]==k){
                    cnt++;
                    s[cnt].l=i,s[cnt].r=j;
                }
            }
        }
        sort(s+1,s+cnt+1,cmp);
        int ans=0,zr=0;
        for(int i=1;i<=cnt;i++){
            if(s[i].l>zr){
                ans++;
                zr=s[i].r;
            }
        }
        cout<<ans;
    }
    return 0;
}
