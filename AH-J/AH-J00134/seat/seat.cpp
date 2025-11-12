#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t=0;
    cin>>n>>m;
    if(n==0||m==0){
        cout<<0<<" "<<0;
        return 0;
    }
    cin>>a[1];
    int y=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==y){
            t=i;
        }
    }
    int x=t/n+(t%n!=0);
    t%=n;
    if(t==0) t=n;
    if(x%2==0) t=n+1-t;
    cout<<x<<" "<<t;


    return 0;
}
