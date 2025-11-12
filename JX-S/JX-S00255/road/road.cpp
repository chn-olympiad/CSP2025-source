#include<bits/stdc++.h>
using namespace std;
long long maxn=0;
const long long N=0x3f3f;
long long a[N][5];
int M;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        M=a[i][1]<a[i][2]? a[i][1]:a[i][2];
        maxn+=M;
    }
    int s=-1;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
                cin>>a[i][j];
            s=s<a[i][j]? s:a[i][j];
        }
    }
    maxn+=s;
    cout<<maxn;
    return 0;
}
