#include <bits/stdc++.h>
using namespace std;
int n,m,a[111],x[25][25],r_score,k=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r_score;
    a[1]=r_score;
    for (int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+1+n*m,cmp);
    for (int i=1;i<=m;i++){
        if (i%2==0){
            for (int j=n;j>=1;j--){
                x[j][i]=a[k];
                if (a[k]==r_score){
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
        else{
            for (int j=1;j<=n;j++){
                x[j][i]=a[k];
                if (a[k]==r_score){
                    cout<<i<<" "<<j;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}
