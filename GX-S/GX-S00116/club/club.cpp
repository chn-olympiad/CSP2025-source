#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
        int t,e[7]={0,0,0,0,0,0};
        cin>>t;
        for(int p=1;p<=t;p++){
            int n;
            cin>>n;
            int a[100005][4],b[100005],c[100005][4],f[100005][4],d[4]={0,0,0,0};
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    cin>>a[i][j];
                    c[i][j]=a[i][j];
                    f[i][j]=a[i][j];
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                        if(a[i][j]>=a[i][1]&&a[i][j]>=a[i][2]&&a[i][j]>=a[i][3]){
                            b[i]=j;
                }
            }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=3;j++){
                    for(int w=j;w<=3;w++){
                        if(f[i][j]>f[i][w]){
                            swap(f[i][j],f[i][w]);
                        }
                        if(c[i][j]>c[i][w]){
                            swap(c[i][j],c[i][w]);
                        }
                    }
                }
            }
        for(int i=1;i<=n;i++){
                if(b[i]==1){
                    d[1]=d[1]+1;
                }
                if(b[i]==2){
                    d[2]=d[2]+1;
                }
                if(b[i]==3){
                    d[3]=d[3]+1;
                }

        }
        for(int i=1;i<=n;i++){
                            e[p]=e[p]+c[i][3];
                        }

            if(d[1]<=n/2){
                for(int i=1;i<=d[i];i++){
                        for(int j=i;j<=d[i];j++)
                            if(b[i]==1&&d[i]==1){
                                if(c[i][3]>c[j][3]){
                                    swap(c[i][3],c[j][3]);
                        }
                    }
            }
                    for(int i=1;i<=d[i]-n/2;i++){
                        e[p]=e[p]-c[i][3]+c[i][2];}
            }
            if(d[2]<=n/2){
                for(int i=1;i<=d[i];i++){
                        for(int j=i;j<=d[i];j++)
                            if(b[i]==1&&d[i]==1){
                                if(c[i][3]>c[j][3]){
                                    swap(c[i][3],c[j][3]);
                        }
                    }
            }
                    for(int i=1;i<=d[i]-n/2;i++){
                        e[p]=e[p]-c[i][3]+c[i][2];}
            }
             if(d[3]<=n/2){
                for(int i=1;i<=d[i];i++){
                        for(int j=i;j<=d[i];j++)
                            if(b[i]==1&&d[i]==1){
                                if(c[i][3]>c[j][3]){
                                    swap(c[i][3],c[j][3]);
                        }
                    }
            }
                    for(int i=1;i<=d[i]-n/2;i++){
                        e[p]=e[p]-c[i][3]+c[i][2];}
            }


        }
        for(int m=1;m<=t;m++){
            cout<<e[m];
        }
        return 0;

}


