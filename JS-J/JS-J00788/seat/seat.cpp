#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,h,l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    sort(a,a+m*n);
    for(int i=0;i<n*m;i++){
        if (a[i] == x)
            x=n*m-i;
    }
    for(int i=0;i<n*m;i++){
        cout<<a[i]<<" ";
    }
    cout<<"|"<<x<<endl;
    if (x % n ==0){
        if ( (x / n) % 2 == 0) h = 1;
        else h = n;
    }
    else{
        if ((x / n) % 2 == 1) h = n- x%n +1;
        else  h = x%n;
    }
    cout<<endl<<x/n<<endl;
    if (x%n == 0) l = x/n;
    else l = x/n + 1;
    cout<< l <<" "<< h ;
    return 0;
}
