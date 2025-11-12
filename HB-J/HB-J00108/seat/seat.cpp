#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int n,m;
struct st{
    int id,sc;
}t[101];
bool cmp(st a,st b){
    return a.sc>b.sc;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>t[i].sc;
        t[i].id=i;
    }
    sort(t+1,t+n*m+1,cmp);
    for (int i=1;i<=n*m;i++){
        if(t[i].id==1){
            // cout<<i<<":";
            int r=(i+n-1)/n;
            cout<<r<<" ";
            if(r%2==1){
                int cnt=(r-1)*n;
                cout<<i-cnt;
            }
            else{
                int cnt=(r-1)*n;
                cout<<m+1-(i-cnt);
            }
            return 0;
        }
    }
    return 0;
}