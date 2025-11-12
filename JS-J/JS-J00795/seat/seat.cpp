#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[(i-1)*n+j];
        }
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            int c=i/n+1*(i%n!=0),r=0;
            if(c%2!=0){
                r=i%n+n*(i%n==0);
            }else{
                r=n-(i%n+n*(i%n==0))+1;
            }
            cout<<c<<' '<<r;
            break;
        }
    }
    return 0;
}
