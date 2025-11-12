#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,k,ans,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]){
                if(a[i+1]){
                    ans++;
                    i++;
                }
            }else{
                ans++;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(a[i])ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
