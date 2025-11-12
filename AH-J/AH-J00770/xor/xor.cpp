#include<bits/stdc++.h>
using namespace std;
long long he[1005][1005]={0};
long long cnt,fcnt;
struct dn{
long long i;
long long j;
bool l=0;
}cn[100005];
bool cmp(dn a,dn b){
    return a.i<b.i;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
long long n,k;
cin>>n>>k;
long long a[n+10];
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
long long d=1;
for(long long i=1;i<=n;i++){
    for(long long j=i;j<=n;j++){
        he[i][j]=he[i][j-1]^a[j];
        he[i][i]=a[i];
        if(he[i][j]==k){
            cn[d].i=i;
            cn[d].j=j;
            //
            cnt++;
            d++;
        }
    }
}
for(long long i=1;i<=n;i++){
    if(cn[i+1].i<=cn[i].j){
        if(cn[i].l==0&&cn[i+1].l==0){
            cn[i+1].l=1;
        }
    }
}
for(long long i=1;i<=n;i++){
    if(cn[i].l==1&&cn[i].i!=0&&cn[i].j!=0){
        fcnt++;
    }
}
cnt-=fcnt;
cout<<cnt;

    return 0;
}
