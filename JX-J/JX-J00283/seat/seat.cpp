#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,chengji[10005];cin>>n>>m;
    for(int i=1;i<=m*n;i++) cin>>chengji[i];
    int r = chengji[1],o = 1;
    sort(chengji+1,chengji+m*n+1);
    int n1= n,m1= m;
    n = m = 1;
    if(chengji[m1*n1] == r) {cout<<1<<" "<<1;return 0;}
    for(int i=m1*n1;i>=1;i--){
        if(chengji[i] == r) cout<<m<<" "<<n;
        n+=o;
        if(n>n1 || n<1){o = -o;m++;n+=o;}
    }
    return 0;

}
