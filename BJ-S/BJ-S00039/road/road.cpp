#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    int n,m,k,cnt=0,money;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int city1,city2;
        cin>>city1>>city2>>money;
        cnt+=money;
    }
    cout<<cnt;
    return 0;
}
