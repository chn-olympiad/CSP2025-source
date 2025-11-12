#include <bits/stdc++.h>
using namespace std;
int a[103];
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    int x=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,greater<int>());
    int cnt=0;
    while(1){
       cnt++;
       if(a[cnt]==x){
          int p=cnt/n;
          int q=cnt%n;
          if(q!=0){
            if(p%2==0){
                cout<<p+1<<" "<<q<<endl;
            }else if(p%2==1){
                cout<<p+1<<" "<<n+1-q<<endl;
            }
          }
          else if(q==0){
            if(p%2==0)cout<<p<<" "<<1<<endl;
            else if(p%2==1)cout<<p<<" "<<n<<endl;
          }
          return 0;
       }
    }
    return 0;
}
