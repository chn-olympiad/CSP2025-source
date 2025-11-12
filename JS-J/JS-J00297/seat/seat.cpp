#include<bits/stdc++.h>
using namespace std;
int a[200],b[200],xR,mc,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) xR=a[i];
        b[a[i]]=1;
    }
    for(int i=100;i>=1;i--){
        if(b[i]) mc++;
        if(i==xR) break;
    }
    x=ceil(mc*1.0/n);
    if(x%2==1) {
        y=mc-(x-1)*n;
//        cout<<"mc:"<<mc<<"n:"<<n<<endl;
    }
    else y=n-(mc-(x-1)*n)+1;
    cout<<x<<' '<<y<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
