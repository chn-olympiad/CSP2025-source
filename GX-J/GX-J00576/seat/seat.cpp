#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m
    cin>>n>>>m;
    int a[110]

    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+n*m+1,a+1);
    for(int i=0;i<n*m;i++){
        if(a[i]=s){
            int t=i+1;
        }
    }
    if(t%4==0){
        cout<<(t-t%n)/n<<" ";
        int h=(t-t%n)/n;
    }
    else{
    cout<<(t-t%n)/n+1<<" ";
         int h=(t-t%n)/n+1;
    }
    if(h%2==1){
    cout<<t-(h-1)*4;
    }
    else{
    cout<<n+1-(t-(h-1)*4);
    }
    return 0;
}
