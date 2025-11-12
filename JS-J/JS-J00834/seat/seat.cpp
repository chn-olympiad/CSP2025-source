#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,l,a[109];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++)cin>>a[i];
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(i=1;i<=n*m;i++)if(a[i]==k){
        l=i;
        break;
    }
//    cout<<l<<endl;
    cout<<(l-1)/m+1<<" ";
    if(((l-1)/m+1)%2==1)cout<<(l-1)%m+1;
    else cout<<m-(l-1)%m;
    return 0;
}
