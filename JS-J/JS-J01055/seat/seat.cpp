#include<bits/stdc++.h>
using namespace std;
int n,m,r,sum=1,x;
int main(){
    cin>>n>>m;
    cin>>r;
    for(int i=2;i<=n*m;i++){
        cin>>x;
        if(x>r){
            sum++;
        }
    }
    cout<<(sum-1)/n+1<<' ';
    if((sum/n+1)%2==1){
        cout<<sum%n;
    }
    else{
        int y=0;
        if(sum%n!=0)y=1;
        cout<<n+y-(sum%n);
    }
    return 0;
}
