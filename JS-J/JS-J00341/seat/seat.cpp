#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,a[N],cnt,k,t,x,y;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==cnt){
            cnt=i;
            break;
        }
    }
    //cout<<cnt<<endl;
    if(cnt%n==0){
        x=cnt/n;
        k=n;
    }else{
        x=cnt/n+1;
        k=cnt%n;
    }
    if(x%2==1){
        cout<<x<<' '<<k;
    }else{
        cout<<x<<' '<<(n-k+1);
    }
    return 0;
}
