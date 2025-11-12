#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int a,int b){
    return a>b;
}
void solve(int loc){
    int x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==loc)break;
        if((x%2==1&&y==n)||(x%2==0&&y==1))x++;
        else if(x%2==0)y--;
        else y++;
    }
    cout<<x<<' '<<y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int loc=a[1];
    sort(a+1,a+1+n*m,cmp);
    solve(loc);
    return 0;
}
