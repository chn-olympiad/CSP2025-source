#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        int q[100001][3];
        cin>>x;
        int a=0,b=0;
        bool c=true;
        int sum1[3];
        for(int o=0;o<=3;o++){
            sum1[o]=0;
        }
        int sum2=0;
        int d=x/2;
        for(int j=1;j<=x;j++){
            for(int g=1;g<=3;g++){
                int y;
                cin>>y;
                q[j][g]=y;
            }
        }
        while(c){
            int mi=-100;
            c=false;
            for(int r=1;r<=x;r++){
                for(int u=1;u<=3;u++){
                    if(mi<q[r][u]){
                            mi=q[r][u];
                            a=r,b=u;
                        }
                }
            }

            if(sum1[b]<d){
                sum1[b]++;
                sum2+=mi;
            }
            for(int v=1;v<=3;v++){
                q[a][v]=0;
            }
            for(int p=1;p<=x;p++){
                for(int t=1;t<=3;t++){
                    if(q[p][t]!=0){
                        c=true;
                    }
                }
            }
        }

        cout<<sum2<<endl;
    }
}
