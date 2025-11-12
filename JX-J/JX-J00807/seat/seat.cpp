#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101]={},t=0,s=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            s=i;
            break;
        }
    }
    if(s%n==0){
        cout<<s/n<<" ";
        if((s/n)%2==0){
            cout<<1;
        }
        else{
            cout<<n;
        }
    }
    else{
        cout<<s/n+1<<" ";
        if((s/n+1)%2==0){
            cout<<n-s%n+1;
        }
        else{
            cout<<s%n;
        }
    }
    return 0;
}
