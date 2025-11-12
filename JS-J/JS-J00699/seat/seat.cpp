#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N=20;
int a[110];
int n,m;

void solve(int x){
    // cerr<<x<<" "<<(x-1)/n<<" "<<((x-1)/n)%2<<endl;
    for(int i=1,cnt=0;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                if(cnt==x){
                    cout<<j<<" "<<i<<endl;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                cnt++;
                if(cnt==x){
                    cout<<j<<" "<<i<<endl;
                }
            }
        }
    }
    return;
}

signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            cnt++;
        }
    }
    solve(cnt);
    fclose(stdin);fclose(stdout);
    return 0;
}