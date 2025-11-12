#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
int n,k,ans,a[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(k==0){
        for(int i=0;i<n;i++){
            if(a[i]==1){
                if(a[i+1]==1){
                    ans++;
                    i++;
                }
            }
            else{
                ans++;
            }
        }
        cout<<ans;
    }
    else{
        for(int i=0;i<n;i++){
            if(a[i]==1) ans++;
        }
        cout<<ans;
    }
    return 0;
}