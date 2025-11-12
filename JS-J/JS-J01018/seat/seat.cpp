#include <bits/stdc++.h>
using namespace std;
const int N=103;
int n,m,a[N],k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) k=a[i];
    }
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1,c=1,r=1;i<=n*m;i++){
        if(a[i]==k) return cout<<c<<" "<<r<<"\n",0;
        if(c%2==0&&r==1||c%2==1&&r==n) c++;
        else if(c&1) r++;
        else r--;
    }
    return 0;
}
