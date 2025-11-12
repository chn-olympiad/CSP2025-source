#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen(seat.out;"i";stdin);
    freopen(seat.out;"w";stdout);
	int n,m,k=0;
	cin>>n>>m;
    char a[n*m];
    for(int i=0;i<=n*m;i++){
        cin>>a[i];
        if(a[0]<a[i]){
            k++;
            cout<<k;
        }
    }
    if(k<=n){
        cout<<"1"<<" "<<k+1;
    }else{
        if(k>n&&k/n%2!=0){
            cout<<k/n+1<<" "<<n-k%n+1;
        }else{
            cout<<k/n+1<<" "<<k-k/n*n+1;
        }
    }
    return 0;
}
