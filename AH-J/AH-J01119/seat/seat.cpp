#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,x,y,R,cnt=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>R;
    for(int i=1;i<n*m;i++){
        cin>>a;
        if(a>R)
            cnt++;
    }
    x=ceil(cnt*1.0/n);
    y=cnt%n;
    if(x%2==0)
        y=n-y+1;
    if(x%2==1&&y==0)
        y=n;
    if(x%2==0&&y==n+1)
        y=1;
    cout<<x<<" "<<y;
    return 0;
}
