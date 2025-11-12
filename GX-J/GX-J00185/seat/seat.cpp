#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1007;
ll n,m,a[N],b[N][N],cnt,c,p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    c=a[1];
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                cnt++;
                b[i][j]=cnt;
            }
        }else{
            for(int j=m;j>=1;j--){
                cnt++;
                b[i][j]=cnt;
            }
        }
    }
    sort(a+1,a+1+n*m,greater<ll>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==c){
            p=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==p){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    return 0;
}
