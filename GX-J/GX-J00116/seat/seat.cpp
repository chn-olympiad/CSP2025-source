#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int v[15][15];
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sum=a[1],l=0;
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        l++;
        if(a[i]==sum){
            sum=l;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(i!=1&&j==1){
                    v[j][i]=v[1][i-1]+1;
                }else{
                    v[j][i]=v[j-1][i]+1;
                }
                if(v[j][i]==sum){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                if(j==n){
                    v[j][i]=v[n][i-1]+1;
                }else{
                    v[j][i]=v[j+1][i]+1;
                }
                if(v[j][i]==sum){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }

    return 0;
}
