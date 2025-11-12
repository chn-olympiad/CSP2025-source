#include<bits/stdc++.h>
using namespace std;
struct abc{
    int x;
    bool f=false;
}a[105];
bool cmp(abc h,abc g){
    return h.x>g.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a[1].f=true;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].x;
    }
    sort(a+1,a+n*m+1,cmp);
    int p=1;
    while(!a[p].f)p++;
    cout<<(p-1)/n+1<<" ";
    if((p-1)%(n*2)+1<=n)cout<<(p-1)%(n*2)+1;
    else cout<<2*n-((p-1)%(n*2));
    return 0;
}
