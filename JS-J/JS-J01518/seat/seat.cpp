#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k;
priority_queue<int> q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    k=a[1];
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(q.top()==k){
                    cout<<i<<" "<<j;
                    return 0;
                }
                q.pop();
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(q.top()==k){
                    cout<<i<<" "<<j;
                    return 0;
                }
                q.pop();
            }
        }
    }
    return 0;
}
