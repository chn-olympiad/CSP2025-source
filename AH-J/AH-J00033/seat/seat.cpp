#include <bits/stdc++.h>
using namespace std;
const long long N=20;
long long n,m,s[N*N][N*N],a[N*N],x,tot;
bool cmp(const long long &x,const long long &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    long long i=1,j=1;
    while(1){
        if(tot==n*m) break;
        s[i][j]=a[++tot];
        if(j%2==0){
            i--;
            if(i<1){
                i=1;
                j++;
            }
        }
        else{
            i++;
            if(i>n){
                i=n;
                j++;
            }
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++)
            if(s[i][j]==x) cout<<j<<" "<<i;
    }
    return 0;
}
