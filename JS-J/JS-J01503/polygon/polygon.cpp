#include<bits/stdc++.h>
using namespace std;
int n;
int a[10010];
int dp[10010];
long long tot=0;
void f(int ans,int k,int mx,bool flag){
    if(k>n) return;
    if(ans>(mx*2) && mx!=-1 && flag==true) tot=(tot+1)%998244353;
    f(ans+a[k+1],k+1,a[k+1],true);
    f(ans,k+1,mx,false);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    f(a[1],1,a[1],true);
    f(0,1,-1,false);
    cout<<tot<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
