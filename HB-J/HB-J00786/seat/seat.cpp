#include <bits/stdc++.h>
#define ll long long
#define el endl
using namespace std;
const ll N=1e6;
int n,m,a[N],sum=0;
void solve(){
   cin>>n>>m;
   int num=n*m;
   for(int i=1;i<=num;i++)cin>>a[i];

   int ret=a[1];

   sort(a+1,a+num+1,greater<int>());
   for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==ret){
                break;
            }
            else sum++;
        }
   }
   for(int i=1;i<=m;i++){
       for(int j=1;j<=n;j++){
            if(i*j==sum){
               cout<<i<<" "<<j;
               return ;
            }

        }
   }


}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int  T=1;//cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
