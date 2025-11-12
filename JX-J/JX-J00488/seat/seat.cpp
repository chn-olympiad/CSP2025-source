#include<bits/stdc++.h>
using namespace std;
int n,m,k,t=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>k;
    for(int i=1;i<n*m;i++){
        int x;cin>>x;
        if(x>k) t++;
    }
    if(t%n==0){
        cout<<t/n<<" ";
        if(t/n%2==1){
            cout<<n;
        }
        else cout<<1;
    }
    else{
        cout<<t/n+1<<" ";
        if((t/n+1)%2==1){
            cout<<t%n;
        }
        else{
            cout<<n-(t%n)+1;
        }
    }
    return 0;
}