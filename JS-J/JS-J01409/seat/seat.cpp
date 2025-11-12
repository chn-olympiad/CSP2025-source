#include <bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,b;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)r=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            b=i;
            break;
        }
    }
    int x=ceil(b*1.0/n),y;
    if(b%n==0){
        if(x%2==1)y=n;
        else y=1;
    }
    else{
        int c=b-n*(x-1);
        if(x%2==1)y=c;
        else y=n-c+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
