#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
const int MOD=998244353;
int n,m,kk;
int a[1005];
int b[105][105];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    kk=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    //for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
    int x=0,y=1,cnt=0;

    //2 2
    //98 99 100 97


    while(1){
        if(y%2==1){
            for(int i=1;i<=n;i++){
               x++;
               b[x][y]=a[++cnt];
               if(a[cnt]==kk){
                   cout<<y<<" "<<x<<endl;
                   return 0;
               }

            }
            y++;
            b[x][y]=a[++cnt];
            if(a[cnt]==kk){
                   cout<<y<<" "<<x<<endl;
                   return 0;
            }
        }
        if(y%2==0){
            for(int i=n;i>=2;i--){
               x--;
               b[x][y]=a[++cnt];
               if(a[cnt]==kk){
                   cout<<y<<" "<<x<<endl;
                   return 0;
               }

            }
            y++;
            b[x][y]=a[++cnt];
            if(a[cnt]==kk){
                   cout<<y<<" "<<x<<endl;
                   return 0;
            }
        }
    }
}
