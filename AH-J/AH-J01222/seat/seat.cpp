#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int R=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            int c=(i+n-1)/n,r=i%n;
            if(r==0)r=n;
            if(c%2==0)r=n-r+1;
            cout<<c<<" "<<r;
            return 0;
        }
    }
    return 0;
}

