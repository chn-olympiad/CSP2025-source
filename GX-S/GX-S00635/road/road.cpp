#include <bits/stdc++.h>
using namespace std;
struct e{
    int a;
    int b;
    int c;
}d[1000010];
int main(){
    freopen("road4.in","r",stdin);
    freopen("road4.out","w",stdout);
    long long n,m,k,f,g,maxn=0,sum=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>d[i].a>>d[i].b>>d[i].c;
    }
    for(int i=1;i<=k;i++){
        cin>>f;
        for(int j=1;j<=n;j++){
            cin>>g;
            maxn=max(maxn,g);
        }
    }
    sum+=maxn;
    maxn=0;
    cout<<sum;
    return 0;
}
/*


*/
