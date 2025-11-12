#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f,t;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];f=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m/2;i++){
        for(int j=1;j<=n;j++,t++)if(a[t+1]==f)cout<<i<<" "<<j;
        for(int j=n;j>=1;j--,t++)if(a[t+1]==f)cout<<i+1<<" "<<j;
    }
    if(m%2==1)for(int j=1;j<=n;j++,t++)if(a[t+1]==f)cout<<m<<" "<<j;
    return 0;
}
