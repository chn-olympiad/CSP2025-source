#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[111];
int bef;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<(n*m);i++){
        cin>>a[i];
        if(a[i]>=a[0]) bef++;
    }
    int x=ceil((double)(bef+0.00)/(double)(n+0.00));
    int y=bef%n;
    if(y==0) y=n;
    if(x%2==0) y=n-y+1;
    printf("%d %d\n",x,y);
    return 0;
}
/*
JJJJJJJJJJ   RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
J   JJ       RP++
JJ  JJ       RP++
 JJJJ        RP++
*/
//09:02 AC
