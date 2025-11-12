#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],num,t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        scanf("%d",a[i]);
    num=a[1];
    sort(a+1,a+1+(n*m),cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==num){
            t=i;
            break;
        }
    int l=t/n,r=t%n;
    if(r==0){
        if(l%2==0)
            cout<<l<<" "<<1;
        else
            cout<<l<<" "<<n;
    }
    else{
        if(l%2==0)
            cout<<l+1<<" "<<r;
        else
            cout<<l+1<<" "<<n-r+1;
    }
    return 0;
}
