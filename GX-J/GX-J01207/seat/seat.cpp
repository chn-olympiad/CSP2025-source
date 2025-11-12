#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.cpp","r",stdin);
    //freopen("number.cpp","w",stdout);
    int m,n,c,d,x;
    cin>>n>>m;
    d=m*n;
    int a[d];
    for(int i=1;i<=d;i++){
        cin>>a[i];
    }
    for(int i=1;i<=d;i++){
        for(int j=1;j<=d;j++){
            if(a[j]<a[j+1]){
                c=a[j];
                x=a[j+1];
                a[j+1]=c;
                a[j]=x;
            }
        }
    }
    for(int i=1;i<=d;i++){
        cout<<a[i]<<" ";
    }
}
