#include<bits/stdc++.h>
using namespace std;
int n,m,a,s,g;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&s);for(int i=1;i<n*m;i++)scanf("%d",&a),g+=(a>s);
    printf("%d %d",g/m+1,g%n*((g/m%2)?-1:1)+n*((g/m%2)?1:0)+((g/m%2)?0:1));
    return 0;
}
