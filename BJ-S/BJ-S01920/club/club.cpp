#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(n==2){
            int ans=0;
            for(int i=1;i<=n;i++){
                cin>>a[i].x>>a[i].y>>a[i].z;
                ans+=max(a[i].x,max(a[i].y,a[i].z));
            }
            cout<<ans;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}