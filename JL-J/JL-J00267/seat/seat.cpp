#include<bits/stdc++.h>
using namespace std;
int a[101];
int b[11][11];
bool cmp(int a,int b){
    if(a<b)
    return b<a;;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                b[i][j]=a[x];
                x++;
            }
        }else{
            for(int j=n;j>=1;j--){
                b[i][j]=a[x];
                x++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==t){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;

}
