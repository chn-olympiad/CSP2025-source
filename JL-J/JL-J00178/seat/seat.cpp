#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000],b[100][100],r;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(r==a[i]){
            r=i;
            break;
        }
    }
    int w=1;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                if(w==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                else{
                    w++;
                }
            }
        }
        else{
            for(int j=1;j<=n;j++){
                if(w==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                else{
                    w++;
                }
            }
        }
    }
    return 0;
}
