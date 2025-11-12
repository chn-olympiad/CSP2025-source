#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int s[N+10][N+10],r[N+10];
int n,m,x,y=-1,c;
struct node{
    int id,num;
}a[N*N+10];
bool cmp(node x,node y){
    return x.num>y.num;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i].num,a[i].id=i;
    sort(a+1,a+n*m+1,cmp);
    for(int i=0;i<n;i++) r[i]=i+1,r[i+n]=n-i;
    while(++c<=n*m){
        x=c/n+(c%n==0?0:1);
        y=(y+1)%(2*n);
        if(a[c].id==1){
            cout<<x<<" "<<r[y]<<"\n";
            break;
        }
    }
    return 0;
}