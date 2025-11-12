#include <bits/stdc++.h>
using namespace std;
int n,m,x,c,r;
bool cmp(int a,int b){
    return a>b;
}
int a[1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        //cout<<a[i]<<endl;
        if(a[i]==x){
            //cout<<i<<"i"<<endl;
            if(i%n)c=(i/n)+1;
            else c=i/n;
            if(c%2==1)r=(i-1)%n+1;
            else r=n-i%n+1;
            break;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}