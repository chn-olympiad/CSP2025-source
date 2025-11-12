#include<bits/stdc++.h>
using namespace std;
int n,m,r,p;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++){
        cin>>a[i];
        if(i==1) r=a[i];
    }
    for(int i=1;i<=p-1;i++){
        for(int j=1;j<=p;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=p;i++){
        if(a[i]==r){
            int y=i;
            if((y/n)%2==0){
                if(y%n==0){
                    cout<<(y/n)+1<<' '<<n;
                }
                else{
                    cout<<(y/n)+1<<' '<<y%n;
                }
            }
            else{
                if(y%n==0){
                    cout<<(y/n)<<' '<<n;
                }
                else{
                    cout<<(y/n)<<' '<<y%n;
                }
            }
        }
    }
    return 0;
}
