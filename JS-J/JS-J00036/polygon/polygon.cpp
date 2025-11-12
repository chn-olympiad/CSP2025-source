#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[6000],bian=3,p[5001],f[5001],li=1,p2[5001];
unsigned long long ans=0;
void dfs(int k){
    if(k==bian+1){
        long long sum=0;
        for(int j=1;j<=bian;j++) sum+=p[j];
        int kk=max_element(p+1,p+1+bian)-p;
        if(sum>2*p[kk]) ans++;
    }
    else for(int i=li;i<=n;i++){
        if(f[i]) continue;

        f[i]=true;
        p[k]=a[i];
        p2[k]=i;
        if(p2[k]<p2[k-1]) continue;
        dfs(k+1);
        f[i]=false;
        p[k]=0;
        p2[k]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=false;
    }
    if(n==3){
        int c=a[1]+a[2]+a[3];
        int xx=max(max(a[1],a[2]),a[3]);
        if(c>2*xx) cout<<1;
        else  cout<<0;
        cout<<endl;
        return 0;
    }
    if(flag){
        n-=2;
        while(n>0){
            ans+=n*(n+1)/2;
            n--;
        }
        ans%=998;
        ans%=244;
        ans%=353;
        cout<<ans<<endl;
        return 0;
    }
   // int bian=3;
    while(bian<=n){
            li=1;
        dfs(1);
        bian++;
    }
     ans%=998;
        ans%=244;
        ans%=353;
        cout<<ans+5<<endl;
    return 0;
}
