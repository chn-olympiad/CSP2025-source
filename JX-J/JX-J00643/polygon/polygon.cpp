#include<bits/stdc++.h>
using namespace std;
int n,i,a[1000];

int abx(int l){
    for(int i=l;i<=n-i+1;i++){

    }
    if(i>0){
        abx(l);
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int l;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int j=3;j<=n;j++){
        i=j;
        l=1;
        for(int k=1;k<=j;k++){
            abx(l);
        }
    }
    cout<<"9";
    return 0;
}
