#include<bits/stdc++.h>
using namespace std;
struct x{int t;bool g;x():g(true){};};
x a[500010];
int cnt=0;
int n,k;
int xorlr(int l,int r,int c){
    //cout<<c<<"\n";
    if(l-1==r){
        return c;
    }
    if(!a[l].g){
        return -1;
    }
    return xorlr(l+1,r,(c^a[l].t));
}
int f(int l,int r){
    int t=xorlr(l+1,r,a[l].t);
    if(t==k){
        for(int i=l;i<=r;i++){
            a[i].g=false;
        }
        cnt++;return r;
    }if(r==n)return r;
    return f(l+1,r+1);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf(" %d",&a[i].t);
        if(a[i].t==k)cnt++,a[i].g=false;
    }
    //cout<<xorlr(2,3,a[1].t);return 0;
    for(int i=2;i<=n-i;i++){
        f(1,1+i);
    }
    printf("%d",cnt);
    return 0;
}
