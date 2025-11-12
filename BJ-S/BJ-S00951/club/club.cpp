#include<bits/stdc++.h>
using namespace std;
int ans[6];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","W",stdout);
    int t;
    cin>>t;
    int j = 1;
    while(t--){
        int n;
        cin>>n;
        int g[1000000];
        if(n == 2){
            int a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            int h = max(a+e+f,max(b+d+f,c+d+e));
            ans[j++] = h;
        }else{
            for(int i = 1;i<=n;i++){
                int tb,tc;
                cin>>g[i];
                cin>>tb>>tc;
            }
            sort(g+1,g+n+1);
            long long h = 0;
            for(int i = n;i>=n/2;i--){
                h+=g[i];
            }
            ans[j++] = h;
        }
    }
    for(int i = 1;i<j;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
