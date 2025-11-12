#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
int n,a[N],maxn=0;
long long ans=0;
bool ok;
void dfs(int x,int k,int num,int c)
{
    if(ok)return ;
    //cout<<x;
    if(c==k){
        if(num>(a[x]*2)){
            ans=(ans+1)%mod;
            //cout<<" "<<ans<<' '<<num<<endl;
        }
        else ok=1;
        return ;
    }
    for(int i=x+1;i<=(n-k+c+1);i++)
    {
        num+=a[i];c++;
        dfs(i,k,num,c);
        num-=a[i];c--;
        ok=0;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);}
    sort(a+1,a+n+1);
    if(n<=2){
        cout<<0;
        return 0;}
    if(n==3){
        if((a[1]+a[2]+a[3])>a[3]*2){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(maxn==1){
        for(int j=3;j<=n;j++){
            int num=1;
            int k1=min(j,n-j),k2=max(j,n-j);
            for(int i=k2+1;i<=n;i++)num*=i%mod;
            for(int i=2;i<=k1;i++)num/=i%mod;
            ans+=num%mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=(n-2);i++)
    {
        for(int j=3;j<=(n-i+1);j++){
            ok=0;
            dfs(i,j,a[i],1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
