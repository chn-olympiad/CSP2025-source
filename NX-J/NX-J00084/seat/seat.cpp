#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,n1,m1;
    cin>>n>>m;
    int a[n*m];
    int b,c=a[0];
    for (int i=0;i<n*m;i++){
        cin>>a[i];
    }
    for (int i=1;i<n*m;i++)
    {
        if (a[i-1]<a[i]){
            b=a[i-1];
            a[i-1]=a[i];
            a[i]=b;
        }
    }
    for (int i=0;i<n*m;i++){
        if (a[i]==c){
            n1=i%n;
            m1=i/n+1;
            if (m1%2==0){
                n1=n-n1;
            }
        }
    }
    cout<<m1<<" "<<n1;
    return 0;
}
