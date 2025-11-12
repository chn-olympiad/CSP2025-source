#include<bits/stdc++.h>
using namespace std;
int n,m,mn,a[205],score,wei;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    mn=n*m;
    for(int i=1;i<=mn;i++){
        cin>>a[i];
    }
    score=a[1];
    sort(a+1,a+1+mn,cmp);
    for(int i=1;i<=mn;i++){
        if(a[i]==score){
            wei=i;
            break;
        }
    }
    if(wei%n==0){
        cout<<wei/n<<" ";
        if((wei/n)%2==1) cout<<n;
        else cout<<1;
        return 0;
    }
    else{
        cout<<wei/n+1<<" ";
        if((wei/n+1)%2==1) cout<<wei%n;
        else cout<<n-wei%n+1;
        return 0;
    }
    return 0;
}
