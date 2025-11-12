#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20;
int n,m,k,a1,a[N*N],p[N][N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++)
                p[j][i]=a[++k];
        }
        else{
            for(int j=n;j>=1;j--)
                p[j][i]=a[++k];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(p[i][j]==a1){
                cout<<j<<" "<<i<<"\n";
                return 0;
            }
    return 0;
}