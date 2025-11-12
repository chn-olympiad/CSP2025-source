#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005],x;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b=n*m;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+1+b,cmp);
    for(int i=1;i<=b;i++){
        if(a[i]==x){
            int c=((i-1)/n)+1,d=(i-1)%n,r;
            if(c%2==0){
                r=n-d;
            }
            else{
                r=d+1;
            }
            cout<<c<<' '<<r;
            return 0;
        }
    }
    for(int i=1;i<=b;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}