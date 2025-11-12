#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1009];
int d;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    d=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int id=(j-1)*n;
            if(j%2==0){
                id+=(n-i+1);
            }else{
                id+=i;
            }
            if(a[id]==d){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}