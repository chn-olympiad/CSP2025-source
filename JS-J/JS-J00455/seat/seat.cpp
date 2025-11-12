#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=0;
    int q=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]!=q) continue;
        else{
            cnt=n*m-i+1;
            break;
        }
    }
    int c=1;
    while(cnt>n){
        cnt-=n;
        c++;
    }
    if(c%2==0) cout<<c<<" "<<n-cnt+1<<endl;
    else cout<<c<<" "<<cnt<<endl;
    return 0;
}
