#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            sum++;
        }
    }
    int x=sum%m;
    if((sum/m+1)%2==0){
        int u=(sum/m+1);
        sum-=(sum/m)*m;
        cout<<u<<" "<<m-sum;
    }else{
        int u=(sum/m+1);
        sum-=(sum/m)*m;
        cout<<u<<" "<<sum+1;
    }
    return 0;
}
