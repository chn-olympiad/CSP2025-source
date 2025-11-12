#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct seat{
    int x;
    int id;
}a[105];
bool cmp(seat a,seat b){
    return a.x>b.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    bool f=true;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            ++cnt;
            int k=j;
            if(!f)k=n-j+1;
            if(a[cnt].id==1){
                cout<<i<<" "<<k;
                return 0;
            }
        }
        f=!f;
    }
    return 0;
}
