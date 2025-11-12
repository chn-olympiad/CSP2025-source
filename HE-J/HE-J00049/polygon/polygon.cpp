#include<bits/stdc++.h>
using namespace std;
int n;
int a[6000];
int m=0,k=1,sl=0;
int s(int p){
    //3
    int u=p+2;
    for(int i=u;i<n-2;i++){
        if(a[p]+a[k]+a[i]>2*max(max(a[p],a[k]),a[i])){
            cout<<a[p]<<" "<<a[k]<<" "<<a[i]<<endl;
            sl++;
        }
    }
}
int main(){
    /*freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);*/
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        s(i);
    }
    cout<<9;
    return 0;
}

