#include<bits/stdc++.h>
#define int long long
#define F(i,n,m) for(int i=n;i<=m;i++)
#define f(i,n,m) for(int i=n;i<m;i++)
#define FF(i,n,m) for(int i=n;i>=m;i--)
#define ff(i,n,m) for(int i=n,i>=m;i--)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int N=2e1+10;
int sn,sm,n,m,op;
struct Node{
    int x,id=0;   
}a[N];
bool cmp(Node a,Node b){
    return a.x>b.x;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    F(i,1,m)
        F(j,1,n)
            cin>>a[(i-1)*n+j].x;
    a[1].id=1;
    sort(a+1,a+n*m+1,cmp);
    F(i,1,m)
        F(j,1,n)
            if(a[(i-1)*n+j].id==1){
                sm=i; sn=j;
                break;
            }
    if(sm%2==0) sn=n-sn+1;
    cout<<sm<<' '<<sn;
    return 0;
}