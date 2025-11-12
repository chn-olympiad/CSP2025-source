#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=5e3+10;
int n,a[N],cnt,b[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            for(int k=0;k<=j-i-2;k++){
                if(b[j]-b[i+k-1]+b[k]>a[j]*2){
                    cnt=cnt%998%244%353+1;
                }
            }
        }
    }
    cout<<cnt%998%244%353;
    return 0;
}
