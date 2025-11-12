#include<bits/stdc++.h>
using namespace std;
int a[114514],b[114514],c[114514],ans=0,s[114514],y[114514],m[114514],x[114154];
int t,n;
struct aa{
    int d1,d2,d3;
    bool xz=false;
};
int dfs(int a,int b,int c){
    if(a==n&&b==n&&c==n){
        return ans;
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
            cin>>n;
        if(n==2){
            cin>>s[1]>>s[2]>>s[3];
            cin>>y[1]>>y[2]>>y[3];
            for(int j=1;j<=3;j++){
                for(int t=1;t<=3;t++){
                    if(t==j){
                        break;
                    }
                    ans=max(ans,s[j]+y[t]);
                }
            }
            cout<<ans<<endl;
        }
        else if(n==4){
            cin>>s[1]>>s[2]>>s[3];
            cin>>y[1]>>y[2]>>y[3];
            cin>>m[1]>>m[2]>>m[3];
            cin>>x[1]>>x[2]>>x[3];
            for(int j=1;j<=3;j++){
                for(int t=1;t<=3;t++){

                    for(int j1=1;j<=3;j1++){

                        for(int t1=1;t1<=3;t1++){

                            ans=(ans,s[j]+y[t]+m[j1]+x[t1]);
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}