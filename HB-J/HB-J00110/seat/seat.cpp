#include<iostream>
using namespace std;
int main(){
    int a[100005];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(n<=1){
            if(p==a[i]){
                cout<<i<<' '<<1;
            }
        }
        if(m<=1){
            if(p==a[i]){
                cout<<1<<' '<<i;
            }
        }
    }
    return 0;
}
