#include<bits/stdc++.h>
using namespace std;
int l[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int cnt=0;
    int maxx=0;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        cnt=cnt+l[i];
        maxx=max(maxx,l[i]);
    }
    if(maxx*2<cnt)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}
