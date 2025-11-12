#include<bits/stdc++.h>
using namespace std;
int f[101][101];
int a[1001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) r=a[i];
    }
    sort(a+1,a+(n*m)+1,cmp);
    int nw=1;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                if(a[nw]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                f[j][i]=a[nw];
                nw++;
            }
        }else{
            for(int j=1;j<=n;j++){
                if(a[nw]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                f[j][i]=a[nw];
                nw++;
            }
        }
    }
    return 0;
}































