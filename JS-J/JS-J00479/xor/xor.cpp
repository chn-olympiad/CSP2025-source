#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[5000005],fx[5000005],d[20001][20001];
int yh(int a,int b){
    int a2[23],b2[23],id1=0,id2=0,ans=0;
    memset(a2,0,sizeof(a2));
    memset(b2,0,sizeof(b2));
    while(a){
        if(a&1==1) a2[id1]=1;
        a>>=1;
        id1++;
    }
    while(b){
        if(b&1==1) b2[id2]=1;
        b>>=1;
        id2++;
    }
    for(int i=0;i<max(id1,id2);i++){
        if(a2[i]!=b2[i]) ans+=pow(2,i);
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fx[i]=yh(fx[i-1],a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(yh(fx[j],fx[i-1])==k) d[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            d[i][j]=max(d[i-1][j],d[i-1][j-1]+d[i][j]);
        }
    }
    cout<<d[n][n];
    return 0;
}
