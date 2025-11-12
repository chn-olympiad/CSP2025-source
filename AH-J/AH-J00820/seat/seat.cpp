#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],st[200],h[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>st[i];
    }
    int t=st[1];
    sort(st+1,st+n*m+1,cmp);
    int l=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++) a[j][i]=st[++l];
        }else{
            for(int i=n;i>=1;i--) a[j][i]=st[++l];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a[j][i]==t){
                cout<<j<<" "<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
