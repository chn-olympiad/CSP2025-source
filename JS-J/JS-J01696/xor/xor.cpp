#include <iostream>
#include<cstdio>
using namespace std;
struct Zhanyong{
    int v;
    bool isused;
};
int n,k,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    Zhanyong a[n+2];
    for(int i=1;i<=n;i++){
        a[i].isused=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        if(k==a[i].v){
            ans++;
            a[i].isused=0;
        }
    }
    long long temp_=0;
    for(int i=1;i<=n;i++){
        if(a[i].isused){
            temp_=(temp_^a[i].v);
            if(temp_==k){
                ans++;
                temp_=0;
            }
        }
        else{
            temp_=0;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
