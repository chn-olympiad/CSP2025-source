#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],f[10001][10001],t=1;
struct node{
    long long x,y;
}m[50001];
bool cmp(node g,node f){
    return g.y<f.y;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        f[1][i]=a[i];
    }
    for(long long i=2;i<=n;i++){
        for(long long j=1;j<=n-i+1;j++){
            f[i][j]=f[i-1][j]^a[i+j-1];
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n-i+1;j++){
            if(f[i][j]==k){
                m[t].x=j;
                m[t].y=i+j-1;
                t++;
            }
        }
    }t--;
    sort(m,m+t,cmp);
    long long r=m[1].y,num=1;
    for(long long i=2;i<=t;i++){
        if(m[i].x>r){
            r=m[i].y;
            num++;
        }
    }
    cout<<num;
    return 0;
}
