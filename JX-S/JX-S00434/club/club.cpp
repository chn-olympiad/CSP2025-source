#include<bits/stdc++.h>
using namespace std;
int b[100000][3];
int a=0,d=0,c[10000][4],e[10000],f=0,y[10000],g[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        g[0]=0;
        g[1]=0;
        g[2]=0;
        cin>>d;
        if(d>2){
            for(int j=0;j<d;j++){
                cin>>b[j][0]>>b[j][1]>>b[j][2];
                if(b[j][0]>b[j][1] && b[j][0]>b[j][2]){
                    c[j][0]=0;
                    c[j][1]=min(b[j][0]-b[j][1],b[j][0]-b[j][2]);
                    c[j][2]=max(b[j][0]-b[j][1],b[j][0]-b[j][2]);
                    c[j][3]=0;
                }
                else if(b[j][1]>b[j][0] && b[j][1]>b[j][2]){
                    c[j][0]=0;
                    c[j][1]=min(b[j][1]-b[j][0],b[j][1]-b[j][2]);
                    c[j][2]=max(b[j][1]-b[j][0],b[j][1]-b[j][2]);
                    c[j][3]=1;
                }
                else{
                    c[j][0]=0;
                    c[j][1]=min(b[j][2]-b[j][0],b[j][2]-b[j][1]);
                    c[j][2]=max(b[j][2]-b[j][0],b[j][2]-b[j][1]);
                    c[j][3]=2;
                }
                e[j]=j;
            }
            int x;
            for(int j=0;j<d;j++){
                for(int k=0;k<d;k++){
                    if(c[k+1][1]>c[k][1]){
                        x=e[k];
                        e[k]=e[k+1];
                        e[k+1]=x;
                    }
                }
            }
            for(int j=0;j<d;j++){
                if(g[c[e[j]][3]]<=d/2){
                    y[i]=y[i]+b[e[j]][c[e[j]][3]];
                    cout<<y[i]<<' ';
                }
                else{
                    y[i]=y[i]+b[e[j]][c[e[j]][3]]-c[e[j]][1];
                    cout<<y[i]<<' ';
                }
                g[c[e[j]][3]]++;
            }

        }
        else{
            int a1,a2,a3,a4,a5,a6,b1,b2,b3,b4,b5,b6;
            cin>>a1>>a2>>a3>>b1>>b2>>b3;
            if(a1>a2 && a1>a3){
                a4=a1;
                a5=min(a1-a2,a1-a3);
                a6=1;
            }
            else if(a2>a1 && a2>a3){
                a4=a2;
                a5=min(a2-a1,a2-a3);
                a6=2;
            }
            else{
                a4=a3;
                a5=min(a3-a1,a3-a2);
                a6=3;
            }
            if(b1>b2 && b1>b3){
                b4=b1;
                b5=min(b1-b2,b1-b3);
                b6=1;
            }
            else if(b2>b1 && b2>b3){
                b4=b2;
                b5=min(b2-b1,b2-b3);
                b6=2;
            }
            else{
                b4=b3;
                b5=min(b3-b1,b3-b2);
                b6=3;
            }
            if(a6!=b6){
                y[i]=a4+b4;
            }
            else{
                if(a5<b5){
                    y[i]=a4+b4-a5;
                }
                else{
                    y[i]=a4+b4-b5;
                }

            }
        }
    }
    for(int i=0;i<a;i++){
        cout<<y[i]<<endl;
    }
    return 0;
}

