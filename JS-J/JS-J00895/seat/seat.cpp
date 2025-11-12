#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    k=a[0];
    sort(a,a+n*m);
    int it=lower_bound(a,a+n*m,k)-a+1;
    it=n*m-it+1;
    cout<<(it/n+1)<<" ";
    if((it/n+1)%2==0){
        if(it%n==0)  cout<<1<<endl;
        else  cout<<(n-it%n+1)<<endl;
    }else{
        if(it%n==0)  cout<<n<<endl;
        else  cout<<(it%n)<<endl;
    }
    return 0;
}
