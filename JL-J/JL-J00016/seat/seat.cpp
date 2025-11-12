#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,h,q=0,w=0;
    cin>>n>>m;
    int a[10001];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        h=a[1];
    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[i]<a[i+1]){
                int x=a[i];
                a[i]=a[i+1];
                a[i+1]=x;
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==h){
            h=i;
            break;
        }
    }
    if(h%n==0){
        cout<<h/n<<" ";
        if((h/n)%2==0){
            cout<<"1";
        }else{
            cout<<n;
        }
    }else{
        cout<<h/n+1<<" ";
        if(((h/n)+1)%2==1){
            cout<<h%n;
        }else{
            cout<<((h/n)+1)*n+1-h;
        }
    }
    return 0;
}
