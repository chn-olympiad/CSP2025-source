#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(x==a[i]){
            x=i;
            break;
        }
    }
    if(x%n==0){
        if((x/n)%2==0){
            cout<<x/n<<" "<<1;
        }
        else{
            cout<<x/n<<" "<<n;
        }
    }
    else{
        cout<<x/n+1<<" ";
        if((x/n+1)%2==0){
            cout<<n-x%n+1;
        }
        else{
            cout<<x%n;
        }
    }
    return 0;
}
