#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    c=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==c){
            c=i;
            break;
        }
    }
    if(c%n==0){
        if(c/n%2==0){
            cout<<c/n<<" "<<1;
        }
        else{
            cout<<c/n<<" "<<n;
        }
    }
    else{
        if((c/n+1)%2==0){
            cout<<c/n+1<<" "<<n-(c%n)+1;
        }
        else
            cout<<c/n+1<<" "<<c%n;
    }
    return 0;
}
