#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,q;
    cin>>n>>m;
    int a[m*n];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    q=a[0];
    sort(a,a+(n*m));
    for(int i=0;i<n*m;i++){
        if(q==a[i]){
            q=i+1;
            cout<<q;
            break;
        }
    }
    int row=q/n;
    if(q%n==0){
        if(row%2==0)cout<<1<<" "<<row;
        else cout<<n<<" "<<row;
    }
    else{
        if(row%2==0)cout<<q%n-1<<" "<<(row+1);
        else cout<<n-(q%n)+1<<" "<<(row+1);
    }
    return 0;
}
