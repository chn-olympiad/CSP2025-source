#include<bits/stdc++.h>
#define IO(name) freopen(name".in","r",stdin),freopen(name".out","w",stdout)
using namespace std;
int n,m,a[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    IO("seat");
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int t=a[1],k;
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++)
        if(a[i]==t){k=i;break;}
    cout<<(int)ceil(1.0*k/n)<<' '<<((k%(2*n)<=n)?(k%(2*n)):(2*n+1-k%(2*n)));
    return 0;
}
