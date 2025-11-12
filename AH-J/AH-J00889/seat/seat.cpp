#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int t=a[1];
    sort(a+1,a+1+n*m);
    for(int i=m*n;i>=1;i--){
        if(t==a[i]){
            int sum=m*n-i+1;
            cout<<sum/n+1<<" ";
            if(sum/n%2==1){
                if(sum%n==0)
                    cout<<n;
                else cout<<n-sum%n+1;
            }
            else{
                if(sum%n==0)
                    cout<<"1";
                else
                    cout<<sum%n;
            }
            break;
        }
    }
    return 0;
}
