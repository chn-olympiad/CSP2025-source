#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int biao=a[1];
    int ans=0;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==biao){
            ans=n*m-i+1;
        }
    } 
    int x=0,y=0;
    if(((ans-1)/m+1)%2==0){
        y=n-(ans%n);
        if(y==0)
            y=1;
        else y=y+1;
    }
    else {
        y=ans%n;
        if(y==0){
            y=n;
        }
    }    
    cout<<(ans-1)/n+1<<" "<<y;
    return 0;
}