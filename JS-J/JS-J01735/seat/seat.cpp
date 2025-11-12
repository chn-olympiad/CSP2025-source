#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],em,k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>em;
    a[1]=em;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==em){
            em=n*m+1-i;
            break;
        }
    }
    if(em%n==0){
        k=em/n;
    }
    else{
        k=em/n+1;
    }
    cout<<k<<" ";
    if(k%2==0){
        if(em%n!=0){
            cout<<n-(em%n)+1<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    else{
        if(em%n!=0){
            cout<<em%n<<endl;;
        }
        else{
            cout<<n<<endl;
        }
    }
    
    return 0;
}