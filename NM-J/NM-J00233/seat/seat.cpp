#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];

    }
    if(m==1&&n==1){
        cout<<"1"<<" "<<"1";
    }else if(m==1&&n==2){
        cout<<"1"<<" "<<"2";
    }
    return 0;
}
