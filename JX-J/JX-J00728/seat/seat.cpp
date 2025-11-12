#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],sum=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i!=1&&a[i]>a[1]){
            sum++;
        }
    }
    int x=sum/n;
    int y=sum-x*n;
    if(sum%n!=0) x++;
    cout<<x<<" ";
    if(y==0){
        cout<<n;
    }
    else if(x%2==0){
        cout<<m-y+1;
    }
    else{
        cout<<y;
    }
    return 0;
}
