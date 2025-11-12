#include<bits/stdc++.h>
using namespace std;
int n,m,v,x,k[10000][10000];
int cmp(int b,int c){
    return b>c;
}
int main(){
    cin>>n>>m;
    int a[100];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        v=a[1];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==v){
            x=i;
            break;
        }
    }
    int g=1;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                k[j][i]=a[g];
                g++;
                if(v==k[j][i]){
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
        else{
            for(int j=n;j>0;j--){
                k[j][i]=a[g];
                g++;
                 if(v==k[j][i]){
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    return 0;
}
