#include<bits/stdc++.h>
using namespace std;
int a[500];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int tmp=0;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    tmp=a[1];
    int f=0;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==tmp){
            f=n*m-i+1;
        }
    }
    if(f%n!=0)cout<<f/n+1<<' ';
    else cout<<f/n<<' ';
    bool t=0;
    while(1){
        if(f>n){
            f-=n;
            t=!t;
        }else{
            if(t){
                cout<<n-f+1;
            }else{
                cout<<f;
            }
            break;
        }
    }
    return 0;
}
