#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20][20],s[200],sum;
bool cmp(const long long x,const long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>s[i];
    }
    long long t=s[1];
    sort(s+1,s+1+n*m,cmp);
    for(long long i=1;i<=m;i++){
        if(i%2!=0) for(long long j=1;j<=n;j++) a[j][i]=++sum;
        else if(i%2==0)  for(long long j=n;j>=1;j--)a[j][i]=++sum;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(s[a[i][j]]==t){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
