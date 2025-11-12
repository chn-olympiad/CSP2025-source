#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
priority_queue<int>pq;
int n,m;
int f[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>f[i];
    }int xy=f[1];
    for(int i=1;i<=n*m;i++){
        pq.push(f[i]);
    }for(int i=1;i<=n*m;i++){
        f[i]=pq.top();
        pq.pop();
    }
    //sort(f+1,f+n*m+1,greater<int>());
    bool flag=0;
    for(int i=1;i<=n*m;i++){
        if(xy==f[i]){
            xy=i;
            flag=1;
            break;
        }if(flag){
            break;
        }
    }int x=0;
    if(xy%n==0){
        x=xy/n;
    }else{
        x=xy/n+1;
    }cout<<x<<" ";
    int y=0;
    if(x%2==1){
        y=xy%m;
        if(xy%m==0){
            y=m;
        }
    }else{
        y=m-xy%m+1;
        if(xy%m==0){
            y-=m;
            y++;
        }
    }cout<<y;
    return 0;
}
