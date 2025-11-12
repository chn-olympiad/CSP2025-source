#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int rd[4][100005];
int vil[12][100005];
int ans;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>rd[1][i]>>rd[2][i]>>rd[3][i];
    }
    for(int i=2;i<=n+1;i++){
        for(int j=i;j<=n+1;j++){
            int minvil=0x3f;
            int tmp,tmp2;
            for(int v=1;v<=12;v++){
                tmp2=minvil;
                minvil=min(minvil,((vil[1][i])+(vil[1][j])));
                if(tmp2!=minvil){
                    tmp=v;
                }
                for(int o=1;o<=m;o++){
                    if((rd[1][o]==i)&&(rd[2][o]==j)){
                        if(minvil+vil[v][1]<rd[3][o]){
                            ans+=minvil+vil[v][1];
                        }
                        else{
                            ans+=rd[3][o];
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
