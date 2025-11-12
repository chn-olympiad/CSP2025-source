#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,a[10002],z;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++) cin>>a[i];
    int y=a[1];
    sort(a+1,a+x,cmp);
    for(int i=1;i<=x;i++){
        if(y==a[i]) z=i;
    }
    if(z%n==0) cout<<z/n<<" ";
    if(z%n) cout<<z/n+1<<" ";
    if(z%(n*2)<=n) cout<<z%(n*2);
    else cout<<n*2+1-(z%(n*2));
    return 0;
}
