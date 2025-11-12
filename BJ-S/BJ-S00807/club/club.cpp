#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,ans;
int v[maxn][5],now[maxn],sum[5];
bool f;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0,f=false;
        for(int i=1;i<=3;i++)sum[i]=0;
        for(int i=1;i<=n;i++){
            cin>>v[i][1]>>v[i][2]>>v[i][3];
            now[i]=1,++sum[1];
        }
        for(int i=1;i<=3;i++){
            int m=INT_MAX,dm,mm;
            while(sum[i]>(n/2)){
                m=INT_MAX;
                for(int j=1;j<=n;j++){
                    if(now[j]!=i)continue;
                    if(i==3){
                        for(int k=1;k<3;k++){
                            if(v[j][i]-v[j][k]<m)
                                m=v[j][i]-v[j][k],dm=j,mm=k,f=true;
                        }
                    }else {
                        for(int k=i+1;k<=3;k++){
                            if(v[j][i]-v[j][k]<m)
                                m=v[j][i]-v[j][k],dm=j,mm=k,f=true;
                        }
                    }
                }
                if(f)
                    --sum[i],++sum[mm],now[dm]=mm;
            }
        }
        for(int i=1;i<=n;i++)
            ans+=v[i][now[i]];
        cout<<ans<<endl;
    }
    return 0;
}
