#include<bits/stdc++.h>
using namespace std;

const int N=110;

int n,m;
int a[N],mp[N][N];

bool cmp(const int &x,const int &y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int val=a[1];
    sort(a+1,a+1+n*m,cmp);
    int now=0;
    for(int j=1;j<=m;j++){
        if(j&1){
            for(int i=1;i<=n;i++) mp[i][j]=a[++now];
        }
        else{
            for(int i=n;i>=1;i--) mp[i][j]=a[++now];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(mp[i][j]==val){
                cout<<j<<" "<<i<<'\n';
                return 0;
            }
        }
    return 0;
}