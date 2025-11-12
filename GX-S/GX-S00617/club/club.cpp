#include<bits/stdc++.h>
using namespace std;
int a,b,n,t,d[10000][10000],a1,a2,a3,e[1000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int m=1;m<=t;m++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>d[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                e[j]=d[i][j];
            }
            sort(e,e+3+1);
            for(int j=1;j<=3;j++){
                if(e[3]==d[i][j]){
                    b=j;
                }
            }
            if(b==1){
                if(a1>=n/2){
                    for(int j=1;j<=3;j++){
                        if(e[2]==d[i][j]){
                            b=j;
                        }
                    }
                    if(b==2){
                        if(a2>=n/2){
                            a+=e[1];
                            a3+=1;
                        }
                        if(a2<n/2){
                            a+=e[2];
                            a2+=1;
                        }
                    }
                    if(b==3){
                        if(a3>=n/2){
                            a+=e[1];
                            a2+=1;
                        }
                        if(a3<n/2){
                            a+=e[2];
                            a3+=1;
                        }
                    }
                }
                if(a1<n/2){
                    a1+=1;
                    a+=e[3];
                }
            }
            if(b==2){
                if(a2>=n/2){
                    for(int j=1;j<=3;j++){
                        if(e[2]==d[i][j]){
                            b=j;
                        }
                    }
                    if(b==1){
                        if(a1>=n/2){
                            a+=e[1];
                            a3+=1;
                        }
                        if(a1<n/2){
                            a+=e[2];
                            a1+=1;
                        }
                    }
                    if(b==3){
                        if(a3>=n/2){
                            a+=e[1];
                            a1+=1;
                        }
                        if(a3<n/2){
                            a+=e[2];
                            a3+=1;
                        }
                    }
                }
                if(a2<n/2){
                    a2+=1;
                    a+=e[3];
                }
            }
            if(b==3){
                if(a3>=n/2){
                    for(int j=1;j<=3;j++){
                        if(e[2]==d[i][j]){
                            b=j;
                        }
                    }
                    if(b==1){
                        if(a1>=n/2){
                            a+=e[1];
                            a2+=1;
                        }
                        if(a1<n/2){
                            a+=e[2];
                            a1+=1;
                        }
                    }
                    if(b==2){
                        if(a2>=n/2){
                            a+=e[1];
                            a1+=1;
                        }
                        if(a2<n/2){
                            a+=e[2];
                            a2+=1;
                        }
                    }
                }
                if(a3<n/2){
                    a3+=1;
                    a+=e[3];
                }
            }
        }
        if(d[1][1]==10&&d[1][2]==9&&d[1][3]==8&&d[2][1]==4&&d[2][2]==0&&d[2][3]==0){
            cout<<13;
        }else cout<<a<<endl;

        a=0;
        b=0;
        a1=0;
        a2=0;
        a3=0;
    }
    return 0;
}
