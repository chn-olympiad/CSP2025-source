#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<n*m;i++){
        cin>>a[i];
    }
    int cj=a[0],pm=0;
    sort(a+0,a+i);
    for(i=n*m-1;i>=0;i--){
        pm++;
        if(a[i]==cj){
            break;
        }
    }
    if(pm%n!=0){
        if((pm/n+1)%2==0){
            cout<<pm/n+1<<" "<<n-pm%n+1;
        }else{
            cout<<pm/n+1<<" "<<pm%n;
        }
    }else{
        if((pm/n)%2==0){
            cout<<pm/n<<" "<<1;
        }else{
            cout<<pm/n<<" "<<n;
        }
    }
    return 0;
}

