#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> q;
    int n,m,x=1,y=1,t,dx=1;
    cin>>n>>m;
    for(int i=1; i<=n*m; ++i){
        int a;
        cin>>a;
        if(i==1){
            t=a;
        }
        q.push(a);
    }
    while(!q.empty() && q.top()!=t){
        q.pop();
        if(x==n && dx==1){
            y++;
            dx=-1;
        }else if(x==1 && dx==-1){
            y++;
            dx=1;
        }else{
            x+=dx;
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
