#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=-1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    l=a[1];
    int it=0;
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==l){
            it=i;
        }
    }

    if(it<=n){
        cout<<1<<" "<<it;
    }
    else{
        int x=ceil(it*1.0/n);
        if(x%2==0){
            cout<<x<<" "<<n-it%n+1;
        }
        else{
            cout<<x<<" "<<it%n;
        }
    }
    return 0;
}
