#include<bits/stdc++.h>
using namespace std;
int n,a[10000],f[10000],sum[10000],moddd=998244353;bool b[10000];int op[10000],ans;//xiaBIAO
void dfs(int k){
    if(k==0){
        int l=0;
        for(int i=1;op[i]!=0;i++,l++)f[i]=a[op[i]];
        sort(f+1,f+l+1);
        int ssss=0;
        for(int i=1;i<l;i++)ssss+=f[i];
        if(ssss>f[l])ans++;
        ans%=moddd;
    }
    for(int i=op[k+1]+1;i<=n;i++){
        if(b[i]==0){
            b[i]=1;
            op[k]=i;
            dfs(k-1);
            b[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];sum[i]=sum[i-1]+a[i];}
    if(n<3){
        cout<<0<<endl;
        return 0;
    }
    sort(a+1,a+n+1);



    if(n==3){
        cout<<(a[1]+a[2]>a[3]?1:0)<<endl;
        return 0;
    }
    if(a[n]==1){
        f[3]=1;
        for(int i=4;i<=n;i++){
            f[i]=(f[i-1]*i+1)%moddd;
        }
        cout<<f[n]<<endl;
        return 0;
    }





    for(int i=1;i<=n;i++)
	dfs(i);
    cout<<ans<<endl; 




    return 0;
}
