#include<bits/stdc++.h>
using namespace std;
int n,m,o;
struct node{
    int s;
    bool f;
}a[105];
bool cmp(node x,node y){
    return x.s>y.s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        a[i].f=0;
        cin>>a[i].s;
        if(i==1) a[i].f=1;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].f==1){
            if(i%n==0){
                if((i/n)%2==0) cout<<i/n<<" "<<1;
                else cout<<i/n<<" "<<n;
            }
            else{
                if((i/n)%2==0) cout<<i/n+1<<" "<<i%n;
                else cout<<i/n+1<<" "<<n-i%n;
            }
            return 0;
        }
    }
}
