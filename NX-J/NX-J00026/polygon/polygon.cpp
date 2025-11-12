#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,e;
    longlong x;
    cin<<n;
    cin<<x;
    for(int i;i<=n;i++){
        for(int j;j<=x;j++){
            e=i*n*j;
            if(x<=i||x>=j){
                cout>>e;
            }
        }
    }
    return  0;
}
