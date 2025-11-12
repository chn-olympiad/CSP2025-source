#include <bits/stdc++.h>
using namespace std;
int n,m,a,tmp,cnt=1,ni,mi;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    priority_queue<int> pq;
    for(int i=1;i<=n*m;i++){
        cin>>a;
        if(i==1){
            tmp=a;
        }
        pq.push(a);
    }
    while(pq.top()!=tmp){
        cnt++;
        pq.pop();
    }
    mi=(cnt+n-1)/n;
    if(mi%2==1){
        ni=(cnt+n-1)%n+1;
    }
    else{
        ni=n-(cnt+n-1)%n;
    }
    cout<<mi<<' '<<ni;
    return 0;
}
