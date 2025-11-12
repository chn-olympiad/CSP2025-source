#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k;
int a[500010],maxn,sum[500010],p=1;
int f[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    if(k==1||k==0){
        for(int i=1;i<=n;i++)
            if(a[i]==k) maxn++;
        cout<<maxn;
        return 0;
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
   //     cout<<f[i]<<" ";
        for(int j=p;j<=i;j++){
            if((sum[i]^sum[j-1])==k){
                if(f[j-1]+1>f[i]){
                    f[i]=f[j-1]+1;
                    p=i+1;
                }
            }
        }
    }
    cout<<f[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
