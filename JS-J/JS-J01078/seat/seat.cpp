#include<bits/stdc++.h>
using namespace std;
int a[105]={};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            cnt++;
        }
    }
    cout<<cnt/n+1<<" ";
    int l=cnt;
    while(cnt+1>n){
        cnt-=n;
    }
    int ans=cnt+1;
    if((l/n)%2==1){
        ans=n+1-(cnt+1);
    }
    cout<<ans;
    return 0;
}