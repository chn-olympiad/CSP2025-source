#include <bits/stdc++.h>
using namespace std;
int a[6000];int n;
int sum(int a[],int x){
    int w=0;
    for(int q=0;q<x;q++)w+=a[q];
    return w;
}
#include <bits/stdc++.h>
using namespace std;
int pailie(int n){
    long long s=0;
    if (n%2==0){
        for(int e=1;e<n/2;e++){
            long long fenzi=1;
            for(int r=n;r>n-e;r--)fenzi*=r;
            long long fenmu=1;
            for(int r=1;r<=e;r++)fenmu*=r;
            s+=fenzi/fenmu;
        }
            s*=2;
            long long fenzi=1;
            for(int r=n;r>n/2;r--)fenzi*=r;
            long long fenmu=1;
            for(int r=1;r<=n/2;r++)fenmu*=r;
            s+=fenzi/fenmu;
            }
    else{
        for(int e=1;e<=n/2;e++){
            long long  fenzi=1;
            for(int r=n;r>n-e;r--)fenzi*=r;
            long long fenmu=1;
            for(int r=1;r<=e;r++)fenmu*=r;
            s+=fenzi/fenmu;

        } s*=2;}

        return (s+1)%998244353;
}
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n;
    int ans =0;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if (sum(a,n)==n)cout<<pailie(n)-n-n*(n-1)/2;
    if (n==3){
        if(a[1]+a[0]>a[2])ans=1;
    cout<<ans;}
    if(n==4){
        if(a[0]+a[1]>a[2])ans++;
        if(a[0]+a[1]>a[3])ans++;
        if(a[0]+a[2]>a[3])ans++;
        if(a[1]+a[2]>a[3])ans++;
        if(a[0]+a[1]+a[2]>a[3])ans++;
    cout<<ans;}
    return 0;
    }
