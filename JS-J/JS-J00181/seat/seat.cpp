//v0.1 9:51 math ->100pts
//moni haoxiang ye neng ac(n<=10,m<=10)
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    int target=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r) target=i;
    }
    int x;
    int y=target%n;
    if(y==0){
        y=n;
        x=target/n;
    }else{
        x=target/n+1;
    }
    if(x%2==0){
        cout<<x<<" "<<n-y+1;
    }else{
        cout<<x<<" "<<y;
    }
    return 0;
}
