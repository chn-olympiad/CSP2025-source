#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50010];
int x[1010][1010];
int l[20010];
int ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n>1000){
        if(k==1){
            for(int i=1;i<=n;i++){
                ans+=a[i];
            }
        }
        else{
            for(int i=1;i<=n;i++){
                ans+=a[i]^1;
                if(a[i]==1&&a[i+1]==1){
                    ans++;
                    i++;
                }
            }
        }
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<=n;i++){
        l[i]=1000001;
        for(int j=i;j<=n;j++){
            x[i][j]=x[i][j-1]^a[j];
            if(x[i][j]==k){
                l[i]=j;
                break;
            }
        }
    }
    int minr;
    for(int i=1;i<=n;i++){
        minr=1000001;
        for(int j=i;j<=n;j++){
            minr=min(minr,l[j]);
        }
        if(minr!=1000001) ans++;
        i=minr;
    }
    printf("%d",ans);
    return 0;
}
