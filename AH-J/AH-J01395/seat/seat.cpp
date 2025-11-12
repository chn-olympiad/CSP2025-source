#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=140;
int n,m,x;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    x=n*m;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }int r=a[1];
    sort(a+1,a+x+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                ++cnt;
                if(a[cnt]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=m;j>=1;j--){
                ++cnt;
                if(a[cnt]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
