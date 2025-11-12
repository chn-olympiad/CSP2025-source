#include"iostream"
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    std::cin>>n>>k;
    int dp[n+5][n+5]{},a[n+5]={0};
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            for(int i=l;i<=r;i++){
                dp[l][r]^=a[i];
            }
        }
    }
    //this way can not get a good grades
    int ans=0;
    int l=1,r=1;
    while(l<=r){
        if(dp[l][r]==k){
            ans++;
            l=r+1;
        }
        r++;
        if(r>n){
            l++;
            r=l;
        }
        if(l>n){
            break;
        }
    }
    std::cout<<ans;
    return 0;
}
