#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];
    int rs=a[0];
    sort(a,a+n*m,greater<int>());
    int cnt=0;
    for(int i=0;i<n*m;i++){
        if(a[i]==rs)cnt=i+1;
    }
    int id=0;
    int c,r;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            id++;
            if(id==cnt&&i%2==1){
                c=i;
                r=j;
                break;
            }
            if(id==cnt&&i%2==0){
                c=i;
                r=n-j+1;
                break;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
