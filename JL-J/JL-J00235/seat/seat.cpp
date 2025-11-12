#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+5];
    int x;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1);
    int k=lower_bound(a+1,a+1+n*m,x)-a;
    k=n*m+1-k;
    cout<<k<<endl;
    if(k%n==0){
        cout<<k/n<<" ";
        if(k/n%2==0){
            cout<<1;
        }
        else{
            cout<<n;
        }
    }
    else{
        cout<<k/n+1<<" ";
        if((k/n+1)%2==0){
            cout<<n+1-k%n;
        }
        else{
            cout<<k%n;
        }
    }
    return 0;
}

