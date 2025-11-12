#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int a[1011111];
struct node{
    int e;
    int b;
}p[101111];
int t=1;
void pd(int x,int y){
    int k=0;
    int nx=x,ny=y;
    if(x!=y){
       for(int i=x;i<y;i++){
            k+=a[i+1]|a[i];
    }
     if(k==m){
        p[t].b=nx;
        p[t].e=ny;
        t++;
    }

    }
    else {
        if(a[x]==m){
            p[t].b=nx;
            p[t].e=ny;
            t++;
        }
    }
}

bool cmp(node x,node y){
    return x.e<=y.e;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            pd(i,j);
        }
    }
    sort(p+1,p+t+1,cmp);
    int ot=0;
    for(int i=1;i<=t;i++){
        if(p[i].b>ot){
            ans++;
            ot=p[i].e;
        }
    }
    cout<<ans;
    return 0;
}
