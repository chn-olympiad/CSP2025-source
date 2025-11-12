#include<bits/bits/stdc++.h>
using namespace std;
int a[105];
int x[105],y[105];
int main(){
    freopen("seat.in","r",stdin);
    freoprn("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(y[j]>n*m){
                x[i]=x[i+1];
                y[j]=1;
            }
            if(a[1]==x[i]&&a[1]==y[j]){
                cout<<x[i]<<y[j];
                break;
            }
            y[j+1];
        }
    }
    return 0;
}
