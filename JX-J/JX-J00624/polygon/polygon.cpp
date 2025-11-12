#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long b[5001],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n<3)printf("0");
    else{
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if(n==3){
            if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])printf("1");
            else printf("0");
        }else{
            b[1]=1;
            for(int i=2;i<=n;i++){
                b[i]=i;
                b[i]*=b[i-1];
            }
            for(int i=1;i<=n-2;i++){
                ans+=b[i]*(n-i-1);
            }
        }
        ans%=998244353;
        cout<<ans;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
