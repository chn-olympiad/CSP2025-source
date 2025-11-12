#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,c=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1];
    bool b=false;
    while(1){
        b=false;
        for(int i=2;i<=n*m;i++){
            if(a[i]>a[i-1]){
                int x=a[i-1];
                a[i-1]=a[i];
                a[i]=x;
            }
        }
        for(int i=1;i<=n*m;i++){
            if(a[i]<a[i+1]){
                b=true;
            }
        }
        if(b==false){
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                if(a[c]==s){
                    cout<<i<<" "<<j;
                    return 0;
                }
                c++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[c]==s){
                    cout<<i<<" "<<j;
                    return 0;
                }
                c++;
            }
        }
    }
    return 0;
}
