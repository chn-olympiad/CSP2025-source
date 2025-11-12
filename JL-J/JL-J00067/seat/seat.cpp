#include<bits/stdc++.h>
#define int long long
#define fors(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1500;
int n,m;
struct node{
    int num;
    int z;
}a[N];
bool cmp(node x,node y){
    return x.z>y.z;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fors(i,1,n*m){
        a[i].num=i;
        cin>>a[i].z;
    }
    sort(a+1,a+1+n*m,cmp);
    int t=0;
    fors(i,1,n*m){
        if(a[i].num==1){
            t=i;
            break;
        }
    }
    int r,c;
    c=(t-1)/n+1;
    r=(t-1)%n+1;
    if(c%2==0){
        r=n-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
