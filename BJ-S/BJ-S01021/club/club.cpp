#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int ans[t+1];
    for(int lo=1;lo<=t;lo++){
        int n;
        cin>>n;
        int maia[n+1];
        int maib[n+1];
        int maic[n+1];
        int mani[n+1][4];
        int an=0;
        int bn=0;
        int cn=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>maia[i]>>maib[i]>>maic[i];
            mani[i][1]=maia[i];
            mani[i][2]=maib[i];
            mani[i][3]=maic[i];
        }
        for(int i=1;i<=n;i++){
            int maxx=max(mani[i][1],max(mani[i][2],mani[i][3]));
            int maxab=max(mani[i][1],mani[i][2]);
            int maxbc=max(mani[i][2],mani[i][3]);
            int maxac=max(mani[i][1],mani[i][3]);
            if(mani[i][1]==maxx){
                if(an<=n/2){
                    an++;
                    ans+=mani[i][1];
                }else{
                    if(mani[i][2]==maxbc){
                        if(bn<=n/2){
                            bn++;
                            ans+=mani[i][2];
                        }else{
                            cn++;
                            ans+=mani[i][3];
                        }
                    }else{
                        cn++;
                        ans+=mani[i][3];
                    }
                }
            }else if(mani[i][2]==maxx){
                if(bn<=n/2){
                    bn++;
                    ans+=mani[i][2];
                }else{
                    if(mani[i][1]==maxac){
                        if(an<=n/2){
                            an++;
                            ans+=mani[i][1];
                        }else{
                            cn++;
                            ans+=mani[i][3];
                        }
                    }else{
                        cn++;
                        ans+=mani[i][3];
                    }
                }
            }else{
                if(cn<=n/2){
                    cn++;
                    ans+=mani[i][3];
                }else{
                    if(mani[i][1]==maxab){
                        if(an<=n/2){
                            an++;
                            ans+=mani[i][1];
                        }else{
                            bn++;
                            ans+=mani[i][2];
                        }
                    }else{
                        bn++;
                        ans+=mani[i][2];
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}