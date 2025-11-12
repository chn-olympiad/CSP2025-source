#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int b=a[0];
    sort(a+1,a+n*m+1);
    for(int i=0;i<n*m;i++){
        if(a[i]==b){
            b=i;
            break;
        }
    }
    int c=b/n;
    int d=b%n;
    if(b<n){
        c=1;
    }
    if(d==0){
        cout<<c;
        if(c%2==0){
            cout<<n-d+1;
        }else{
            cout<<d;
        }
    }else{
        cout<<c+1;
        if((c+1)%2==0){
            cout<<n-d+1;
        }else{
            cout<<d;
        }
    }
    return 0;
}
