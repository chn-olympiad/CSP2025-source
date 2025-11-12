#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
     for(int i=0;i<m;i++){
        if(a[i]>a[i+1]){
            int n;
            n=a[i];
            a[i]=a[i+1];
            a[i+1]=n;
        }
    }
    cout<<a[m-1];
    return 0;
}
