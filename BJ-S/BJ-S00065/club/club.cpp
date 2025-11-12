#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int dx,dy,dz;
}a[N];
int t,n,dp[N];
int num(int x,int y,int z){
    if(x>y&&x>z)return x;
    else if(y>z&&y>x)return y;
    return z;
}
void work(int w){
   dp[0]=0;
   for(int i=1;i<=n;i++){
        for(int j=w;j>=1;j--){
            dp[j]=max(dp[j],dp[j-1]+num(a[i].dx,a[i].dy,a[i].dz));
        }
   }
   cout<<dp[w]<<endl;
}
bool cmp(node s1,node s2){
    return s1.dx>s2.dx;
}
void work1(int w){
   sort(a+1,a+n+1,cmp);
   int ans=0;
   for(int i=1;i<=w;i++)ans+=a[i].dx;
   cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,-0x3f,sizeof(dp));
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].dx>>a[i].dy>>a[i].dz;
            if(a[i].dz==0)cnt++;
        }
        if(cnt==n)work1(n/2);
        else work(n);
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
