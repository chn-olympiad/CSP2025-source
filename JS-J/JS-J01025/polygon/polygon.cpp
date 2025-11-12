#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ls[5001],r1[7501501],r2[5001],tot=0;
int cnt=0;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    r1[0]=0;
    r2[0]=0;
    for(int i=1;i<=n;i++){
        cin>>ls[i];
        r2[i]=ls[i];
        r2[i]+=r2[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cnt++;
            if (j==i){
                r1[cnt]=ls[j];
            }
            else{
                r1[cnt]=max(ls[j],r1[cnt-1]);
            }
        }
    }
    for(int i=1;i<=n-3+1;i++){
        for(int j=i+2;j<=n;j++){
            if (r2[j]-r2[i-1]>2*r1[((2*n-i+2) * (i-1)) / 2+(j-i+1)]){
                tot++;
                int temp=r2[j]-r2[i-1]-2*r1[((2*n-i+2) * (i-1)) / 2+(j-i+1)];
            }
        }
    }

    cout<<tot;
}
