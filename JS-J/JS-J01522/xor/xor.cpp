#include <bits/stdc++.h>
using namespace std;
struct qujian{
    int l,r;
}c[24000000];
int a[500010],n,m;
bool cmp(qujian k,qujian p){
    return k.r<p.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i,j,o,t,f=0,u=1,tp;
    cin>>n>>m;
    for(i=0;i<=n-1;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=n-i;j++){
            t=0;
            for(o=j;o<=j+i-1;o++){
                t=t^a[o];
            }
            if(t==m){
                c[f].l=j;
                c[f].r=j+i-1;
                f=f+1;
            }
        }
    }
    sort(c,c+f,cmp);
    tp=c[0].r;
    for(i=1;i<=f-1;i++){
        if(c[i].l>tp){
            u=u+1;
            tp=c[i].r;
        }
    }
    cout<<u;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
