#include <bits/stdc++.h>
#define ll long long
#define str string
#define N 10003
using namespace std;

bool st;
pair<int,int> a[N];
bool ed;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    fprintf(stderr,"%lf\n",(&ed-&st)/1024.0/1024);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n*m,greater<pair<int,int>>());
    for(int i=1;i<=n*m;i++){
        if(a[i].second==1){
            int x=(i-1)/n+1;
            int y=(i-1)%n+1;
            printf("%d %d\n",x,(x&1?y:n-y+1));
            break;
        }
    }
    return 0;
}
