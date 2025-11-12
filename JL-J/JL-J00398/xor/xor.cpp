#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[15][15],n,m,b[105],c,d;
int main(){
    freopen("xor.in","w",stdin);
    freopen("xor.out","r",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    d=b[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(b[j]>b[i]){
                c=b[j];
                b[j]=b[i];
                b[i]=c;
            }
        }
    }
    c=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            c++;
            if(b[c]==d){
                cout << i << j;
                return 0;
            }
        }
        i++;
        for(int j=n;j>=1;j--){
            c++;
            if(b[c]==d){
                cout << i << j;
                return 0;
            }
        }
    }
    return 0;
}

