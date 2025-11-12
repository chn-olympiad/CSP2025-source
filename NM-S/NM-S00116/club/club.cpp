#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        int n;
        cin>>n;
        int a[4][n+10]= {0};
        for(int i=1; i<=n; i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
        }
        for(int i=1;i<=n;i++){
            int maxx=-1;
            for(int j=1;j<=3;j++){
                if(maxx<a[j][i])
                    maxx=a[j][i];
            }
            //cout<<"maxx:"<<maxx<<endl;
            ans+=maxx;
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
