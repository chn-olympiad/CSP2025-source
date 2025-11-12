#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k;
    int a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=i;i<=n*m;i++){
        if(a[i]==k){
            int x=(i-1)/n+1;
            int y=i-n*(x-1);
            cout<<x<<" "<<y;
            return 0;
        }
    }
    return 0;
}
