#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=150;
int n,m,a1,a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    a1=a[1],sort(a+1,a+n*m+1,greater<int>());
    int i=1,j=1;
    for(int p=1;p<=n*m;p++){
        if(a[p]==a1)break;
        if(i&1)j++;else j--;
        if(j==n+1)i++,j=n;
        if(j==0)i++,j=1;
    }
    cout<<i<<' '<<j<<"\n";
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}