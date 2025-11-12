#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;
    int x=0,y=0,z=0;//1,0,11
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            x++;
            if(f==1){
                z++;
                f=0;
            }
            else{
                f=1;
            }
        }
        else{
            y++;
            f=0;
        }
    }


    int ans=0,xx=-1;
    bool ff=0;
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            ff=0;
        }
        else{
            if(ff==0){
                xx=a[i];
                ff=1;
            }
            else{
                xx^=a[i];
                if(xx==k){
                    ans++;
                    xx=-1;
                    ff=0;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
//1234过了，56没过
//什么思路啊？
//就这样吧
//rp++rp++rp++++++++++++++
//多过点数据吧，求你了CCF
