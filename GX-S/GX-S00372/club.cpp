#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long st1[100001],st2[100001],st3[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long dp1[50001],dp2[50001],dp3[50001],fi=0,se=0,th=0;
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    memset(dp3,0,sizeof(dp3));
    long long t,n,p,maxi;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>st1[i]>>st2[i]>>st3[i];
        st1[0]=0;st2[0]=0;st3[0]=0;
        dp1[1]=st1[1];dp2[1]=st2[1];dp3[1]=st3[1];
        p=n/2;
        fi=0,se=0,th=0;
        bool used;
        for(int i=2;i<=n;i++){
           maxi=-1;
           if((dp1[i-1]>dp2[i-1]) && (dp2[i-1]>dp3[i-1])){
                maxi=dp1[i-1];
                ++fi;
           }
           if((dp2[i-1]>dp1[i-1]) && (dp1[i-1]>dp3[i-1])){
                maxi=dp2[i-1];
                ++se;
           }
           if(maxi==-1){
                maxi=dp3[i-1];
                ++th;
           }
              if(fi==p){
                 if(i>2)dp1[i]=max(dp1[i-1]-st1[i-2]+st1[i],dp1[i-1]);
                 else {
                       if(se<p && dp1[i-1]<dp2[i-1]+st1[i]){
                            dp1[i]=dp2[i-1]+st1[i];
                            ++se;
                            used=true;
                       }
                       if(th<p && dp1[i-1]<dp3[i-1]+st1[i]){
                            if(used){
                                if(dp3[i-1]+st1[i]>dp2[i-1]+st1[i]){
                                    --se;
                                    ++th;
                                    dp1[i]=dp3[i-1]+st1[i];
                                }
                            }
                            else{
                                ++th;
                                dp1[i]=dp3[i-1]+st1[i];
                            }
                       }
                 }
              }
              else{
                 dp1[i]=maxi+st1[i];
              }
              used=false;
              if(se==p){
                  if(i>2)dp2[i]=max(dp2[i-1]-st2[i-2]+st2[i],dp2[i-1]);
                 else {
                         if(fi<p && dp2[i-1]<dp1[i-1]+st2[i]){
                            dp2[i]=dp1[i-1]+st2[i];
                            ++fi;
                            used=true;
                       }
                       if(th<p && dp2[i-1]<dp3[i-1]+st2[i]){
                            if(used){
                                if(dp3[i-1]+st2[i]>dp1[i-1]+st1[i]){
                                    --fi;
                                    ++th;
                                    dp2[i]=dp3[i-1]+st2[i];
                                }
                            }
                            else{
                                ++th;
                                dp2[i]=dp3[i-1]+st2[i];
                            }
                       }
                 }
              }
              else{
                  dp2[i]=st2[i]+maxi;
              }
              used=false;
              if(th==p){
                  if(i>2)dp3[i]=max(dp3[i-1]-st3[i-2]+st3[i],dp3[i-1]);
                 else {
                         if(se<p && dp3[i-1]<dp2[i-1]+st3[i]){
                            dp3[i]=dp2[i-1]+st3[i];
                            ++se;
                            used=true;
                       }
                       if(fi<p && dp3[i-1]<dp1[i-1]+st3[i]){
                            if(used){
                                if(dp1[i-1]+st3[i]>dp2[i-1]+st3[i]){
                                    --se;
                                    ++fi;
                                    dp3[i]=dp1[i-1]+st3[i];
                                }
                            }
                            else{
                                ++fi;
                                dp3[i]=dp1[i-1]+st3[i];
                            }
                       }
                 }
              }
              else{
                    dp3[i]=st3[i]+maxi;
              }
        }
        maxi=max(dp1[n],dp2[n]);
        maxi=max(maxi,dp3[n]);
        cout<<maxi<<endl;
    }
    return 0;
}
