#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;
int T,n,m;
int a[3][N];
ll ans;
bool check1,check2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    frropen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[2][i]!=0) check1=1;
            if(a[3][i]!=0) check2=1;
        }
        if(check1==0 && check2==0){
           sort(a[1]+1,a[1]+n+1);
            for(int i=m+1;i<=n;i++)
                ans+=a[1][i];
            cout<<ans<<"\n";
        }else if(check2==0){
            continue;
        }else{
            continue;
        }
    }
    return 0;
}
