#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int n,m;
int a[N];
int ans[N][N];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                ans[j][i]=a[++cnt];
            }
        } else {
            for(int j=n;j>=1;j--){
                ans[j][i]=a[++cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==x){
                cout<<j<<" "<<i<<"\n";
                return 0;
            }
        }
    }
    return 0;
}