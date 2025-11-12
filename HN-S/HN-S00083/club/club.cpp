#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
int n,t,sum;
struct A{
    int a,b,c;
    bool f;
}a[maxx];
void zj(int x,int pea,int peb,int pec,int y){
    if(pea>n/2||peb>n/2||pec>n/2) return ;
    if(x==n+1){
        sum=max(sum,y);
        return ;
    }
    zj(x+1,pea+1,peb,pec,y+a[x].a);
    zj(x+1,pea,peb+1,pec,y+a[x].b);
    zj(x+1,pea,peb,pec+1,y+a[x].c);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        int pma=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        zj(1,0,0,0,0);
        cout<<sum<<'\n';
    }
    return 0;
}
