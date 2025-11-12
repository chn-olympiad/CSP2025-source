#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long c[10006][10006];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,c1,c2,w,kk=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>c1>>c2>>w;
        c[min(c1,c2)][max(c1,c2)]=w;
    }
    for(int i=1;i<=k;i++){
        int qc;
        cin>>qc;
        long long b[10005];
        for(int j=1;j<=n;j++){
            cin>>b[j];
        }
        for(int j=1;j<n;j++){
            for(int h=j+1;h<=n;h++){
                c[j][h]=min(c[j][h],qc+b[j]+b[h]);
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;i<=n;j++){
            kk+=c[i][j];
        }
    }
    cout<<kk;
    return 0;
}
