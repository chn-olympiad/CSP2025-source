#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[2000],b,num,ans_l;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+n*m);
    for(int i=0;i<n*m;i++){
        if(b==a[i]){
            num=n*m-i;
            break;
        }
    }
    if(num%n==0){
        ans_l=num/n;
        cout<<ans_l<<" ";
    }
    else{
        ans_l=num/n+1;
        cout<<ans_l<<" ";
    }
    if(ans_l%2!=0){
        if(num%n==0){
            cout<<n;
        }
        else{
            cout<<num%n;
        }
    }
    else{
       if(num%n==0){
            cout<<"1";
        }
        else{
            cout<<n-num%n+1;
        }
    }
    return 0;
}
