#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
bool cmp(int l,int r){
    return l>r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int w=n*m;
    for(int i=0;i<w;i++){
        cin>>a[i];
    }
    int a1=a[0];
    sort(a,a+w,cmp);
    int u=0;
    for(int i=1;i<=n;i++){
        if(i%2==1)
            for(int j=1;j<=m;j++){
                b[i][j]=a[u];
                if(a[u]==a1){
                    cout<<i<<" "<<j;
                    return 0;
                }
                u++;
            }
        else if(i%2==0)
            for(int j=m;j>=1;j--){
                b[i][j]=a[u];
                if(a[u]==a1){
                    cout<<i<<" "<<j;
                    return 0;
                }
                u++;
            }
    }
    return 0;
}
