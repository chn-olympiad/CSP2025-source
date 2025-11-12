#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],fvv=0;
int b1[12],b2[12];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    fvv=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++)
            if(a[i]<a[j])swap(a[i],a[j]);
    }
    for(int i=1;i<m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                b1[i]=i;
                b2[i]=j;
            }
        }else{
            for(int j=n;j<=1;j--){
                b1[i]=i;
                b2[i]=j;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i]==fvv){
            if(i%2!=0){
                cout<<b1[i]<<" "<<b2[i];
                break;
            }else{
                cout<<b1[i]<<" "<<b2[i];
                break;
            }
        }
        }

    return 0;
}
