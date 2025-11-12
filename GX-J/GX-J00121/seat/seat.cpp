#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n ,m ,c ,r ,x ,y;
    cin >> n >> m;
    int a[n*m];
    for(int i=1 ; i<=n*m ; i++){
        cin >> a[i];
    }
    x=a[1];
    for(int i=1 ; i<=n*m ; i++){
        for(int j=1 ; j<=i ; j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1 ; i<=n*m ; i++){
        if(a[i]==x){
            y=i;
            break;
        }
    }
    if(y/n==1){
        c=1;
    }else{
        c=y/n+1;
    }
    if(y%m!=0){
        r=y%m;
    }else{
        r=m;
    }
    cout << c << " " << r;

    return 0;
}
