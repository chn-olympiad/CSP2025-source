#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m,num=1;
    cin>>n>>m;
    int a[101];
    cin>>a[1];
    for (int i=2;i<=n*m;i++){
        cin>>a[i];
        if (a[i]>a[1]){
            num++;
        }
    }
    if (num%n!=0){
        if ((num/n+1)%2==1){
            cout<<num/n+1<<" "<<num%n;
        }
        else{
            cout<<num/n+1<<" "<<n+1-num%n;
        }
    }
    else{
        if ((num/n)%2==1){
            cout<<num/n<<" "<<n;
        }
        else{
            cout<<num/n<<" "<<1;
        }
    }
    return 0;
}
