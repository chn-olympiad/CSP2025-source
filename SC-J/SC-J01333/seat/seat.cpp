#include<bits/stdc++.h>
using namespace std;
#define db(x...) fprintf(stderr,x)
const int N=105;
int a[N],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    int r;
    for(int i=1;i<=n*m;++i) cin>>a[i];
    r=a[1];
    sort(a+1,a+1+n*m),reverse(a+1,a+1+n*m);
    for(int i=1;i<=n*m;++i)
        if(a[i]==r){
            int l=(i+n-1)/n;
            if(l&1) cout<<l<<" "<<i-(l-1)*n<<"\n";
            else cout<<l<<" "<<l*n-i+1<<"\n";
            break;
        }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//8:45