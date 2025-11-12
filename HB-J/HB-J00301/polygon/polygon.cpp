#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[1000],r[1000];
int digu(int b,int c){
    if(c>m){
        if(m-1>=3){
            digu(b+1,b+3);
        }
        else{
            return k;
        }
    }
    n=r[c]-r[b-1];
    if(n>a[c]*2){
        k++;

        k=k%244;


    }
    digu(b,c+1);
}
int main(){
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        r[i]=r[i-1]+a[i];
    }
    sort(a+1,a+1+m);
    digu(1,3);
    cout<<k;
}
