#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005][25],ans,f,sum[25];
bool check(int a[],int b[]){
    for(int i=1;i<=21;i++){
        if((a[i]-b[i]+2)%2!=sum[i]) return false;
    }
    return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=21;i++){
        sum[i]=k%2;
        k/=2;
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=1;j<=21;j++){
            if(x%2==1) a[i][j]++;
            a[i][j]+=a[i-1][j];
            a[i][j]%=2;
            x/=2;
        }
    }
    f=1;
    for(int i=1;i<=n;i++){
        for(int j=f;j<=i;j++){
            if(check(a[i],a[j-1])){
                ans++;
                f=i+1;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
