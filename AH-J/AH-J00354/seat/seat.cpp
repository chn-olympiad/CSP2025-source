#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1005];
int t;
bool cmp(int x,int y){
return x>y;
}
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
t=a[1];
sort(a+1,a+(n*m)+1,cmp);
int cnt=0;
for(int i=1;i<=n;i++){
    if(i%2==1){
        for(int j=1;j<=m;j++){
                cnt++;
            if(a[cnt]==t){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }else{
        for(int j=m;j>=1;j--){
                cnt++;
            if(a[cnt]==t){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
}
return 0;
}
