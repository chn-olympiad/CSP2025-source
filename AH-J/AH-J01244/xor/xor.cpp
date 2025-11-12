#include<iostream>
using namespace std;
int n,k,a[500005],cnt,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=l+i-1;
        while(r<=n){
            int sum=l;
            for(int j=l+1;j<=r;j++){
                sum=(sum&j);
            }
            if(sum==k){
                cnt++;
                l=r+1;
                r=l+n-1;
            }
            else{
                l++;
                r++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
