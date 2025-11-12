#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    int n,m,a[105]={0},b;
    cin>>n>>m;
    int N=n*m,mp[n][m]={0},k=1;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+N+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[k]==b){
                    cout<<i<<' '<<j;
                    return 0;
                }
                mp[j][i]=a[k];
                k++;
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[k]==b){
                    cout<<i<<' '<<j;
                    return 0;
                }
                mp[j][i]=a[k];
                k++;
            }
        }
    }
    return 0;
}
