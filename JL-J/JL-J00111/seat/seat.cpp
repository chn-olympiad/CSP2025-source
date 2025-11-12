#include<bits/stdc++.h>
using namespace std;
int b[1101];
int main(){
    freopen("number.in","e",stdin);
    freopen("number.out","w",stdout);
    int m,n,c,z,v,q,w,e;
    cin  >>n>> m;
    for (int i=0;i<=m*n;i++){
        cin >> c;
        cin >> b[i];

    }
    for (int i=0;i<=m*n;i++){
        for(int j=b[i];j<=m*n;i++){
            if(b[i]<b[i+1]){
                q=b[i];
                b[i]=b[i+1];
                b[i+1]=q;
        }
    }
    for (int i=0;i<=n*m;i++){
        if(b[i]<c){
            z=i-1;
        }
    }
    v=z-1;
    w=v/n;
    e=z/m;
    if(w==0){
        if(w%2==0){
            cout <<w+1<<" " << n;
        }
        else{
            cout <<w+1 << " " << 1;
        }
    }
    else if (e%2==0){
        cout <<z-e<<e+1;
    }
    else{
        cout <<n+1-z+e<<e+1;
    }
    return 0;
}
