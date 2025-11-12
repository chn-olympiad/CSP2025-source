#include<iostream>
using namespace std;
int n,max_=-1,sum,ans;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        max_=max(a[i],max_);
        sum+=a[i];
    }
    if(n==3){
        if(sum>max_*2){
            ans=1;
        }else{
            ans=0;
        }
    }
    else{
        if(max_==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            ans-=2;
            if(ans%2==0){
                ans=(ans+1)*(ans/2);
            }else{
                ans=(ans+1)*(ans/2)+(ans/2);
            }
        }
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
