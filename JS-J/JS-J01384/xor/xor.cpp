#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,rec;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(k==0){
        for(int i=1;i<=n;++i){
            if(a[i]==0){
                ++ans;
                rec=0;
            }
            else ++rec;
            if(rec==2){
                ++ans;
                rec=0;
            }
        }
        if(rec){
            if(rec%2==0)++ans;
        }
        cout<<ans;
    }
    else{
        for(int i=1;i<=n;++i){
            if(a[i]==1)++ans;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
