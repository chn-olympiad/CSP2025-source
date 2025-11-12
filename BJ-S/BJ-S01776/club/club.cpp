#include<bits/stdc++.h>
using namespace std;
struct node{
    int now[3];
}line[100001];
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n=0,lim;//limit
        int dp[100001],num[100001],f[100001];
        cin>>n;
        lim=n/2;
        for(int i=0;i<3*n;i++){
            cin>>num[i];
            f[i]=i-(i%3);
            dp[i]=0;
        }
        for(int i=0;i<100001;i++){
            line[i].now[0]=0;
            line[i].now[1]=0;
            line[i].now[2]=0;
        }
        /*int rec,maxx=0;
        for(int i=0;i<3;i++){
            if(num[i]>maxx){
                maxx=num[i];
                rec=i;
            }
        }
        for(int i=0;i<3;i++){
            line[i].now[0]=0;
            line[i].now[1]=0;
            line[i].now[2]=0;
            line[i].now[rec]=1;
        }*/

        for(int i=0;i<3*n;i++){
            dp[i]=num[i];
            if(i<3){
                line[i].now[0]=0;
                line[i].now[1]=0;
                line[i].now[2]=0;
                line[i].now[i]=1;
            }
            int loc=-1;
            if(i>=3){
                int maxn2=0;
                for(int j=0;j<3;j++){
                    if(line[f[i-3]+j].now[i%3]+1<=lim){
                        if(dp[i]+dp[f[i-3]+j]>maxn2){
                            maxn2=dp[i]+dp[f[i-3]+j];
                            loc=f[i-3]+j;
                        }
                    }
                }
                dp[i]=maxn2;
                //int cot=0;
                for(int k=0;k<3;k++){
                    if(loc>=0){
                        if(k==i%3)
                            line[i].now[k]=line[loc].now[k]+1;
                        else
                            line[i].now[k]=line[loc].now[k];
                    }
                    else{
                        line[i].now[k]=line[loc].now[k];
                    }
                    //cot++;
                }
            }
        }
        //cout<<dp[3*n-1]<<" ";
        int ans=0;
        for(int i=0;i<3*n;i++){
            ans=max(dp[i],ans);
        }
        cout<<ans;
        cout<<endl;
    }
    return 0;
}
