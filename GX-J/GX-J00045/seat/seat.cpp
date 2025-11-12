#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r=0,b=0,c=0;
    int a[105]={};
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            b=i;
        }
    }
    cout<<b<<endl;
    if(b%n==0){
        cout<<b/n<<" ";
        c=b/n;
        if(c%2==1){
            cout<<n;
        }
        else{
            cout<<1 ;
        }
    }
    else{
        cout<<b/n+1<<" ";
        c=b/n+1;
        if(c%2==1){
            cout<<b%n;
        }
        else{
            cout<<n-b%n+1;
        }
    }
    return 0;
}
