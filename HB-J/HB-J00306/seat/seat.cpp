#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n>>m>>a;
    for(int i=1;i<m*n;++i){
        cin>>b;
        if(b>a)
            ++cnt;
    }
    int k=cnt%n;
    cout<<cnt/n+(bool)k<<' '<<(k ? k : n);
    return 0;
}
