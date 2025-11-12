#include<bits/stdc++.h>
using namespace std;
int n,m,target;
int score[100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cin>>target;score[0]=target;
    for(int i=1;i<n*m;i++)cin>>score[i];
    sort(score,score+m*n);
    for(int i=m*n-1;i>=0;i--){
        if(score[i]==target)
            target=m*n-i-1;
    }
    cout<<target/n+1<<' ';
    if((target/n)%2==0)cout<<target%n+1;
    else cout<<n-target%n;
    return 0;
}
