#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int a[N+5];
int ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int maxn=0;
    int x,y,z;
    cin>>x>>y>>z;
    int ab,bc;
    for(int i=1;i<=y;i++){
        cin>>ab>>bc>>a[i];
    }
    sort(a+1,a+y+1);
    for(int i=1;i<=y-1;i++){
        ans+=a[i];
    }
    cout<<ans-maxn;
    return 0;
}
