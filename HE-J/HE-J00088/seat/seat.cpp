#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int mp[15][15];
int xx,yy;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r_score=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int k=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                mp[i][j]=a[k];
                k++;
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                mp[i][j]=a[k];
                k++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]==r_score){
                xx=i;
                yy=j;
            }
        }
    }
    cout<<xx<<" "<<yy;
    return 0;
}
