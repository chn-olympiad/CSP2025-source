#include<bits/stdc++.h>
using namespace std;

long long a[120];
int id;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=n*m;
    for(int i=1;i<=cnt;i++)cin>>a[i];
    int d=a[1];
    sort(a+1,a+cnt+1,greater<int>());
    for(int i=1;i<=cnt;i++){
        cout<<a[i]<<' ';
        if(a[i]==d){
            id=i;
            cout<<'\n';
            break;
        }
    }
    cout<<id<<'\n';
    int x,y;
    if(id%n==0)y=id/n;
    else y=id/n+1;
    if(y%2!=0){
       //if(id%n==0)x=m;
       //else x=id%n+1;
       x=(id-1)%n+1;
    }else{
       //if(id%n==0)x=1;
       //else x=n-id%n+1;
       x=n-((id-1)%n+1)+1;
    }
    cout<<y<<' '<<x;
    return 0;
}
