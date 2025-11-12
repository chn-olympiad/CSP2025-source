#include<bits/stdc++.h>
using namespace std;
const int N=1e2+1;
int n,m;
int a[N];
int score;
int ida[N];
int ids;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(n==1&&m==1)cout<<1<<" "<<1;

    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        ida[i]=i;
    }
    score=a[1];
    sort(a+1,a+1+n+m,cmp);
    for(int i=1;i<=n+m;i++){
        if(a[i]==score) ids=i;
    }
    if(n!=1&&m==1){
        cout<<ids<<" "<<1;
        return 0;
    }
    else if(n==1&&m!=1){
        cout<<1<<" "<<ids;
        return 0;
    }
    else if(ids%2==0) cout<<n-ids%n<<" "<<ids/n+1;
    else cout<<ids%n<<" "<<ids/n+1;
    return 0;
}
