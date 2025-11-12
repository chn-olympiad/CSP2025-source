#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s[105],n,m,tofind,ts;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>s[i];
    tofind=s[1];
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)if(s[i]==tofind)ts=i;
    cout<<ts/n+(ts%n!=0)<<' ';
    if((ts/n+(ts%n!=0))%2==1)cout<<ts%n+n*(ts%n==0);
    else cout<<n-(ts%n+n*(ts%n==0))+1;
    return 0;
}
