#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[505],c[505],n,m,c1[505],ans;
bool h[505];
int t=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        char c1;cin>>c1;
        h[i]=c1-'0';
    }
    for(int i = 1;i<=n;i++){
        cin>>c1[i];
        a[i]=i;
    }
    do{
        for(int i = 1;i<=n;i++){
            c[i]=c1[a[i]];
        }
        int in=0,g=0;
        for(int i = 1;i<=n;i++){
            if(h[i]==0||c[i]<=g){
                g++;
                continue;
            }
            in++;
        }
        if(in>=m)
            ans=(ans+1)%M;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<endl;
    return 0;
}
