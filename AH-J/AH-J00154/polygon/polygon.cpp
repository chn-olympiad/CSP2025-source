#include<bits/stdc++.h>
using namespace std;
int n,k,as=0,i,j;
int a[5010];
int ki(int l,int r){
    int h=0,d=0;
    for(int i=l;i<=r;i++){
        h=h+a[i];
        d=max(d,a[i]);
    }
    if(h>2*d) return 1;
    else return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int p;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p=max(p,a[i]);
    }
    if(p<=1){
        for(i=3;i<=n;i++){
            int c1=1,c2=1;
            for(j=1;j<=i;j++){
                int u=(n+1-j)%998244353;
                c1=c1*u;
                c2=c2*(j%998244353);
            }
            as=as+(c1/c2);
        }
        cout<<as;
    }else{
        for(i=1;i<=n;i++){
            for(j=i+2;j<=n;j++){
                if(ki(i,j)){
                    as++;
                    as%=998244353;
                }
            }
        }
        cout<<as;
    }
    return 0;
}
