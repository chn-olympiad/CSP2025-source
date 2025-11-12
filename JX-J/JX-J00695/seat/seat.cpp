#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int n,m,s;
int a[maxn];
bool cmp(int x,int y) {
    return x>y;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;++i) scanf("%d",&a[i]);
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    int id=1;
    for(int i=1;i<=n*m;++i) if(a[i]==s) id=i;
    int c=(id-1)/n+1;
    printf("%d %d\n",c,(c%2 ? (id-1)%n+1:n-((id-1)%n)));
    return 0;
}
