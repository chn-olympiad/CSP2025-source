#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1000],b=1,x=1,y=1,s=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){cin>>a[i];}
    for(int i=2;i<n*m;i++){
    if(a[i]>a[i+1]){swap(a[i],a[i+1]);}
    }
    for(int i=1;i<=n*m;i++){
    if(a[i]>a[1]){b++;}
    }
    if(b==1){
    cout<<x<<" "<<y;
    return 0;
    }
    for(int i=1;i<=b-1;i++){
    if(x!=n&&s==0){
    x++;
    continue;
    }
    if(x==n&&s==0){
    y++;
    s=1;
    continue;
    }
    if(x!=1&&s==1){
    x--;
    continue;
    }
    if(x==1&&s==1){
    y++;
    s=0;
    continue;
    }
    }
    cout<<y<<" "<<x;
    return 0;
}
