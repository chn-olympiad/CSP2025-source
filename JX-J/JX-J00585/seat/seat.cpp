#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int temp=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int id=0;
    for(int i=1;i<=n*m;i++){
        if(temp==a[i]){
            id=i;
            break;
        }
    }
    if(id%n==0){
        int cnt=id/n;
        if(cnt%2==1){
            cout<<cnt<<" "<<n;
        }
        else{
            cout<<cnt<<" "<<1;
        }
    }
    else{
        int cnt=id/n+1;
        int c=id%n;
        if(cnt%2==1){
            cout<<cnt<<" "<<1;
        }
        else{
            int t=n-c+1;
            cout<<cnt<<" "<<t;
        }
    }
    return 0;
}

