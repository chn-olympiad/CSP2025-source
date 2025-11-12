#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[0],x;
    sort(a,a+(n*m-1));
    int z=0;
    for (int i=n*m;i>=0;i--){
        z++;
        if (a[i]==s){
            x=z;
        }
    }
    int n1,m1;
    if (x%n!=0){
        m1=(x/n)+1;
    }
    else{
        m1=x/n;
    }
    if (m1%2!=0){
        n1=x%n;
    }
    else{
        if (x%n==0){
            n1=1;
        }
        else{
            n1=4-(x%2)+1;
        }
    }
    cout<<n1<<" "<<m1;
    return 0;
}
