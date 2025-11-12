#include <bits/stdc++.h>
using namespace std;
int n,m,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n][m];
int k=0;
int b[n*m];
int l=n*m;
    for(int i=0;i<l;i++){
        cin >>b[i];
    for(int j=0;j<l;j++){
        for(int p=0;p<j;p++){
        if(b[j]<b[p+1]){
        k=b[p+1];
        b[p+1]=b[j];
        b[j]=k;
                }
                c=b[j];
                r=b[p+1];
            }
            cout <<a[c][r];
        }
    }
}
