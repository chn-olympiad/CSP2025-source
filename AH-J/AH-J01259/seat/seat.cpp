#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<1<<" "<<1;
        return 0;
    }
    int sum=n*m-0;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
        k=a[1];
    }
    sort(a+1,a+sum+1);
    if(n<=1&&m>=1&&m<=10){
    for(int i=1;i<=sum;i++){
        if(k=a[i]){
            cout<<1<<" "<<i+1;
        }
        else cout<<"";
    }
    return 0;
    }
    if(m<=1&&n>=1&&n<=10){
    for(int i=1;i<=sum;i++){
        if(k=a[i]){
            cout<<i+1<<" "<<1;
            return 0;
        }
    }
    return 0;
}
return 0;
}
