#include<bits/stdc++.h>
using namespace std;
struct Node{
    int id,soc;
}a[150];
bool cmp(Node a,Node b){
    return a.soc>b.soc;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i].soc;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int now=0;
    for(int i=1;i<=n*m;++i){
        if(a[i].id==1){
            now=i;
            break;
        }
    }

    int c=0,r=now%n;;
    c=now/n+1;
    if(r==0){
        --c;
        r=n;
    }
    if(c%2==0){
        r=n+1-r;
    }
    cout<<c<<" "<<r;
    return 0;
}
