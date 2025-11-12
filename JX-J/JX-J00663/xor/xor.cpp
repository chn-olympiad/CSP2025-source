#include<bits/stdc++.h>
using namespace std;
int n,k;
int m;
int a[5005];
int ans[5005];
struct node{
    int l,r;
}x[5005];
bool cmp(node x,node y){
    if(x.r-x.l!=y.r-y.l)
        return x.r-x.l<y.r-y.l;
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int s=a[i];
        for(int j=i;j<=n;j++){
            if(s==k){
                m++;
                x[m].l=i;
                x[m].r=j;
            }
            s=a[j+1]^s;
        }
    }
    int h=0;
    sort(x+1,x+m+1,cmp);
    for(int i=1;i<=m;i++){
        bool v=0;
        for(int j=x[i].l;j<=x[i].r;j++){
            if(!ans[j])
                ans[j]++;
            else{
                v=1;
                break;
            }
        }
        if(v)
            continue;
        h++;
    }
    cout<<h;
}
