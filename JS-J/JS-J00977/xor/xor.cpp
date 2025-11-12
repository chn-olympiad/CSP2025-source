#include <iostream>
using namespace std;
int xr(int a,int b){
    int ans=0,c,d,e=0,f;
    while(a!=0||b!=0){
        c=a%2;d=b%2;
        if(c!=d){
            f=1;
            for(int i=1;i<=e;i++){
                f*=2;
            }
            ans+=f;
        }
        e++;
        a/=2;b/=2;
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[200000],b,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b=0;
        for(int j=i;i<=n;j++){
            if(xr(b,a[j])==k){
                i=j;
                ans++;
                break;
            }else{
                b=xr(b,a[j]);
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
