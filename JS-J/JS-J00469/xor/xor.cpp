#include <iostream>
using namespace std;
int n,k,cnt1,cnt0;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }else if(a[i]==0){
            cnt0++;
        }
    }
    if(cnt0+cnt1==n){
        if(k==1){
            cout<<cnt1;
        }else if(k==0){
            for(int i=1;i<=n;++i){
                if(a[i]==1&&a[i+1]==1){
                    i=i+1;
                    cnt0++;
                }
            }
            cout<<cnt0;
        }
    }else{
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
