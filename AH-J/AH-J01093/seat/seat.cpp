#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int tn=n*m;
    for(int i=1;i<=tn;i++){
        cin>>a[i];
    }
    int r=a[1],st;
    sort(a+1,a+tn+1);
    for(int i=1;i<=tn;i++){
        if(a[i]==r){
            st=tn-i+1;
        }
    }
    if(st%n==0){
        if((st/n)%2==0){
            cout<<st/n<<" "<<1;
        }
        else{
            cout<<st/n<<" "<<n;
        }
    }
    else{
        if((st/n+1)%2==0){
            cout<<st/n+1<<" "<<n-(st%n)+1;
        }
        else{
            cout<<st/n+1<<" "<<st%n;
        }
    }


    return 0;
}
