#include<bits/stdc++.h>
using namespace std;
struct three{
    long long b[3];
};
int main(){
    ifstream fin("club.in");
    ofstream fout("club.out");
    long long cishu;
    fin>>cishu;
    for(;cishu>=1;cishu--){
        long long a,b,c=0,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t=0,u,v,w,x,y,z;
        fin>>n;
        long long dp[n/2+1][n/2+1][n/2+1]={0};
        for(x=0;x<=n/2;x++){
            for(y=0;y<=n/2;y++){
                for(z=0;z<=n/2;z++){
                    dp[x][y][z]=0;
                }
            }
        }
        vector<three> dp_run;
        dp_run.resize(1);
        dp_run[0].b[0]=dp_run[0].b[1]=dp_run[0].b[2]=0;
        for(a=1;a<=n;a++){
            fin>>x>>y>>z;
            long long size_dp=dp_run.size();
            for(;c<size_dp;c++){
                if(dp_run[c].b[0]+1<=n/2){
                    dp[dp_run[c].b[0]+1][dp_run[c].b[1]][dp_run[c].b[2]]=max(dp[dp_run[c].b[0]+1][dp_run[c].b[1]][dp_run[c].b[2]],dp[dp_run[c].b[0]][dp_run[c].b[1]][dp_run[c].b[2]]+x);
                    t=max(t,dp[dp_run[c].b[0]+1][dp_run[c].b[1]][dp_run[c].b[2]]);
                    //cout<<dp[dp_run[c].b[0]+1][dp_run[c].b[1]][dp_run[c].b[2]]<<"\n";
                    three in;
                    in.b[0]=dp_run[c].b[0]+1;
                    in.b[1]=dp_run[c].b[1];
                    in.b[2]=dp_run[c].b[2];
                    dp_run.push_back(in);
                }
                if(dp_run[c].b[1]+1<=n/2){
                    dp[dp_run[c].b[0]][dp_run[c].b[1]+1][dp_run[c].b[2]]=max(dp[dp_run[c].b[0]][dp_run[c].b[1]+1][dp_run[c].b[2]],dp[dp_run[c].b[0]][dp_run[c].b[1]][dp_run[c].b[2]]+y);
                    t=max(t,dp[dp_run[c].b[0]][dp_run[c].b[1]+1][dp_run[c].b[2]]);
                    three in;
                    in.b[0]=dp_run[c].b[0];
                    in.b[1]=dp_run[c].b[1]+1;
                    in.b[2]=dp_run[c].b[2];
                    dp_run.push_back(in);
                }
                if(dp_run[c].b[2]+1<=n/2){
                    dp[dp_run[c].b[0]][dp_run[c].b[1]][dp_run[c].b[2]+1]=max(dp[dp_run[c].b[0]][dp_run[c].b[1]][dp_run[c].b[2]+1],dp[dp_run[c].b[0]][dp_run[c].b[1]][dp_run[c].b[2]]+z);
                    t=max(t,dp[dp_run[c].b[0]][dp_run[c].b[1]][dp_run[c].b[2]+1]);
                    three in;
                    in.b[0]=dp_run[c].b[0];
                    in.b[1]=dp_run[c].b[1];
                    in.b[2]=dp_run[c].b[2]+1;
                    dp_run.push_back(in);
                }
                //dp_run.erase(dp_run.begin());
            }
        }
        fout<<t<<"\n";
    }
    return 0;
}
