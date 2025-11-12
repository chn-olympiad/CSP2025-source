#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n[t],a[1001][3],e[1001][3],max[10001],h[3],i=1;
    while(i<=t){
        int f=1;
        i++;
        int w=0;
        cin>>n[i];
        for(int j=0;j<n[i];j++){
            for(int k=0;k<3;k++){
                e[j][k]=-1;
            }
        }
        for(int j=0;j<n[i];j++){
            max[j]=-1;
        }
        for(int j=0;j<n[i];j++){
            cin>>a[j][0]>>a[j][1]>>a[j][2];
        }
        int b=n[i]/2;
        h[0]=0;
        h[1]=0;
        h[2]=0;
        for(int j=0;j<n[i];j++){
            for(int k=0;k<3;k++){
                if(max[j]<a[j][k]){
                    max[j]=a[j][k];
                }
            }
            for(int k=0;k<3;k++){
                if(max[j]==a[j][k]){
                    e[j][k]=a[j][k];
                    h[k]++;

                    break;
                }
            }
        }
        while(f!=0){
            if(h[0]>b){
                int p[10001],min=10001,y;
                for(int j=0;j<n[i];j++){
                    p[j]=e[j][0]-a[j][1];
                }
                for(int j=0;j<n[i];j++){
                    if(p[j]<min and e[j][0]!=-1){
                        min=p[j];
                        y=j;
                    }
                }
                e[y][0]=-1;
                e[y][1]=a[y][1];
                h[0]--;
                h[1]++;
            }else if(h[1]>b){
                int p[10001],min=10001,y;
                for(int j=0;j<n[i];j++){
                    p[j]=e[j][1]-a[j][2];
                }
                for(int j=0;j<n[i];j++){
                    if(p[j]<min and e[j][1]!=-1){
                        min=p[j];
                        y=j;
                    }
                }
                e[y][1]=-1;
                e[y][2]=a[y][2];
                h[1]--;
                h[2]++;
            }else if(h[2]>b){
                int p[10001],min=10001,y;
                for(int j=0;j<n[i];j++){
                    p[j]=e[j][2]-a[j][0];
                }
                for(int j=0;j<n[i];j++){
                    if(p[j]<min and e[j][2]!=-1){
                        min=p[j];
                        y=j;
                    }
                }
                e[y][2]=-1;
                e[y][0]=a[y][0];
                h[2]--;
                h[0]++;
            }else{
                for(int j=0;j<n[i];j++){
                    for(int k=0;k<3;k++){
                        if(e[j][k]!=-1){
                            w=w+e[j][k];
                        }
                    }
                }
                cout<<w<<endl;
                f=0;
            }
        }
    }
    return 0;
}
