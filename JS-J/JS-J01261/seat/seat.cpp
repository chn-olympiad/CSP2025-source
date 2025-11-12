#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105]={},p;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    p=a[1];
    sort(a,a+n*m);
    for(int i=n*m;i>0;i--){
        if(p==a[i]){
            p=n*m-i;
            break;
        }
    }
    int c,r,t=0;
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                t++;
                if(t==p){
                    c=i;
                    r=j;
                }
            }
        }
        else{
            for(int j=1;j<=n;j++){
                t++;
                if(t==p){
                    c=i;
                    r=j;
                }
            }
        }

    }



    cout<<c<<" "<<r;

    return 0;
}
