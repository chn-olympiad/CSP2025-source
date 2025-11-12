#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ji,s[105][105],aa=1,bb=1,ans1,ans2;
bool cmp(long long A,long long B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)cin>>a[i];
    ji=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(long long i=1;i<=n*m;i++){
        s[aa][bb]=a[i];
        if(bb&1){
            if(aa==n)bb++;
            else aa++;
        }
        else{
            if(aa==1)bb++;
            else aa--;
        }
    }
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=m;j++)if(s[i][j]==ji)ans1=i,ans2=j;
    cout<<ans2<<' '<<ans1;
    cout<<'\n';
    return 0;
}
