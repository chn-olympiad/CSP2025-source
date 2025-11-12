#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=a[1];
    sort(a+1,a+1+n*m,cmp);
    int p;
    for(int i=1;i<=n*m;i++){
        if(a[i]==cnt){
            p=i;
            break;
        }
    }
    if(p%n==0){
        cout<<p/n<<" ";
        if((p/n)%2==1){
            cout<<n;
        }
        else{
            cout<<1;
        }
    }
    else{
        cout<<p/n+1<<" ";
        if((p/n+1)%2==1){
            cout<<p-p/n*n;
        }
        else{
            cout<<n-p+p/n*n+1;
        }
    }

    return 0;
}
