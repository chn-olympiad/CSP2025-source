#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b[5001];
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            if(a[i]<a[i+1]){
                int x=a[i];
                a[i]=a[i+1];
                a[i+1]=x;
            }
        }
    }
}
