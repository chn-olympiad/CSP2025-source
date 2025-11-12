#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
int t,n;
cin>>t;
int m[10001][3];

for(int i=0;i<t;i++){
        int cnt=0;
int a=0,b=0,c=0;
int za=0,zb=0,zc=0;
int mina[10000]={100000};
int minb[10000]={100000};
int minc[10000]={100000};
    cin>>n;
    int r=n/2;
    for(int j=0;j<n;j++){
        cin>>m[j][0]>>m[j][1]>>m[j][2];
         if(m[j][0]>m[j][1]&&m[j][0]>m[j][2]&&a+1<=r){
            cnt+=m[j][0];
            a+=1;
            for(int k=0;k<j;k++){
                if(m[j][0]<mina[k]){
                        if(k!=0){
                            mina[za+1]=m[i][0];
                            swap(mina[za+1],mina[k+1]);
                            za++;
                            break;
                        }
                    mina[k+1]=m[j][0];
                    za++;
                    break;
                }
            }
         }else if(m[j][1]>m[j][0]&&m[j][1]>m[j][2]&&b+1<=r){
            cnt+=m[j][1];
            b+=1;
            for(int k=0;k<j;k++){
                if(m[j][1]<minb[k]){
                        if(k!=0){
                            minb[zb+1]=m[j][1];
                            swap(minb[zb+1],minb[k]);
                            zb++;
                            break;
                        }
                    minb[k+1]=m[j][1];
                    zb++;
                    break;
                }
            }
         }else if(m[j][2]>m[j][0]&&m[j][2]>m[j][1]&&c+1<=r){
            cnt+=m[j][2];
            c+=1;
            for(int k=0;k<j;k++){
                if(m[j][2]<minc[k]){
                        if(k!=0){
                            mina[zc+1]=m[i][2];
                            swap(minc[zc+1],minc[k]);
                            zc++;
                            break;
                        }
                    minc[k]=m[j][2];
                    zc++;
                    break;
                }
            }
         }else if(m[j][0]>m[j][1]&&m[j][0]>m[j][2]&&m[j][0]>mina[za]){
            cnt=cnt+m[j][0]-mina[za];
            mina[za]=mina[za-1];
            for(int k=0;k<j;k++){
                if(m[j][0]<mina[k]){
                    mina[k+1]=m[j][0];
                    za++;
                    break;
                }
            }
         }else if(m[j][1]>m[j][0]&&m[j][1]>m[j][2]&&m[j][1]>minb[zb]){
            cnt=cnt+m[j][1]-minb[zb];
            if(minb[zb]!=minb[zb-1])
            minb[zb]=minb[zb-1];
            for(int k=0;k<j;k++){
                if(m[j][1]<minb[k]){
                    minb[k+1]=m[j][1];
                    zb++;
                    break;
                }
            }
         }else if(m[j][2]>m[j][1]&&m[j][2]>m[j][1]&&m[j][2]>minc[zc]){
            cnt=cnt+m[j][2]-minc[zc];
            minc[zc]=minc[zc-1];
            for(int k=0;k<j;k++){
                if(m[j][2]<minc[k]){
                    minc[k+1]=m[j][2];
                    zc++;
                    break;
                }
            }
         }
  }
  cout<<cnt<<endl;
}


fclose(stdin);
fclose(stdout);
return 0;
}
