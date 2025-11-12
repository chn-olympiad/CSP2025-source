#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+5],b=1,c;
    cin>>a[1];
    c=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>c)b++;
    }
    int c,r,d=1
    for(int i=1;i<=m;){
        for(int j=1;j<=n;j++){
            if(d==b){
                cout<<i<<j;
                return 0;
            }
            d++;
        }
        i++;
        for(int j=n;j>=1;j++){
            if(d==b){
                cout<<i<<j;
                return 0;
            }
            d++;
        }
        i++;
    }
}
